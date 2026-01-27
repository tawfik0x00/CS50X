#!/usr/bin/env python3
"""
CS50x Final Project: Smart Threaded File Search Tool

A fast, reliable multi-threaded file search with proper thread management
and real-time results display.

Author: Mohamed Tawfik
GitHub: tawfik0x00
"""

import os
import sys
import threading
import argparse
import time
import re
from queue import Queue, Empty
from collections import defaultdict
from pathlib import Path

# ANSI escape codes
class Colors:
    CYAN = '\033[36m'
    YELLOW = '\033[33m'
    GREEN = '\033[32m'
    BLUE = '\033[34m'
    RED = '\033[31m'
    MAGENTA = '\033[35m'
    WHITE = '\033[37m'
    RESET = '\033[0m'
    BOLD = '\033[1m'

# Configuration
DEFAULT_EXTENSIONS = {
    '.txt', '.log', '.conf', '.xml', '.json', '.html', '.htm',
    '.py', '.sh', '.js', '.css', '.cfg', '.ini', '.md', '.yml', '.yaml',
    '.csv', '.java', '.c', '.cpp', '.h', '.php', '.sql'
}

MAX_THREADS = 32
MAX_FILE_SIZE = 5 * 1024 * 1024  # 5 MB for faster scanning
BATCH_SIZE = 100  # Files per batch for progress updates

def print_banner():
    """Prints the application banner with author info."""
    banner = f"""{Colors.CYAN}
    ╔════════════════════════════════════════════════════════════╗
    ║                                                            ║
    ║          {Colors.BOLD}{Colors.WHITE}SMART FILE SEARCH TOOL v1.0{Colors.RESET}{Colors.CYAN}                       ║
    ║          {Colors.BLUE}High-Performance Multi-threaded Scanner{Colors.RESET}{Colors.CYAN}           ║
    ║                                                            ║
    ║      {Colors.YELLOW}Author:{Colors.RESET}     Tawfik                                 ║
    ║      {Colors.YELLOW}GitHub:{Colors.RESET}     tawfik0x00                             ║
    ║                                                            ║
    ╚════════════════════════════════════════════════════════════╝
    {Colors.RESET}"""
    print(banner)

class SmartFileSearch:
    """Smart file search with proper thread management."""

    def __init__(self, root_dir, target_word, extensions=None,
                 max_threads=MAX_THREADS, case_sensitive=False):
        """
        Initialize search tool.
        """
        self.root_dir = os.path.abspath(root_dir)
        self.target_word = target_word
        self.pattern = re.compile(re.escape(target_word),
                                  0 if case_sensitive else re.IGNORECASE)
        self.case_sensitive = case_sensitive
        self.extensions = extensions or DEFAULT_EXTENSIONS.copy()
        self.max_threads = min(max_threads, MAX_THREADS)

        # Queues
        self.file_queue = Queue()
        self.result_queue = Queue()

        # Control flags
        self.running = True
        self.stop_event = threading.Event()

        # Statistics
        self.stats = {
            'total_files': 0,
            'scanned': 0,
            'with_matches': 0,
            'total_matches': 0,
            'errors': 0,
            'start_time': None,
            'last_update': time.time()
        }

        # Results
        self.results = defaultdict(list)

        # Locks
        self.stats_lock = threading.Lock()
        self.print_lock = threading.Lock()

        # Windows color support
        if os.name == 'nt':
            os.system('')

    def collect_files_smart(self):
        """Collect files with yield to avoid memory issues."""
        print(f"{Colors.CYAN}[*] Scanning directory for files...{Colors.RESET}")

        count = 0
        start_time = time.time()

        try:
            for root, dirs, files in os.walk(self.root_dir, followlinks=False):
                # Skip some system directories to speed up
                if any(skip in root for skip in ['.git', '__pycache__', 'node_modules']):
                    dirs[:] = []
                    continue

                for file in files:
                    if self.stop_event.is_set():
                        return count

                    if any(file.lower().endswith(ext) for ext in self.extensions):
                        file_path = os.path.join(root, file)

                        # Check file size quickly
                        try:
                            if os.path.getsize(file_path) <= MAX_FILE_SIZE:
                                self.file_queue.put(file_path)
                                count += 1

                                # Show progress every 1000 files
                                if count % 1000 == 0:
                                    elapsed = time.time() - start_time
                                    rate = count / elapsed if elapsed > 0 else 0
                                    print(f"{Colors.MAGENTA}[*] Found {count} files ({rate:.1f}/sec){Colors.RESET}", end='\r')
                        except (OSError, PermissionError):
                            continue
        except KeyboardInterrupt:
            print(f"\n{Colors.YELLOW}[!] Directory scan interrupted{Colors.RESET}")
            return count

        self.stats['total_files'] = count
        print(f"\n{Colors.GREEN}[✓] Found {count} files to search{Colors.RESET}")
        return count

    def search_worker(self, worker_id):
        """Worker thread for searching files."""
        while self.running and not self.stop_event.is_set():
            try:
                # Get file with timeout to check stop_event
                file_path = self.file_queue.get(timeout=0.1)
            except Empty:
                continue
            except:
                break

            try:
                matches = self.search_single_file(file_path)

                if matches:
                    self.result_queue.put((file_path, matches))

                # Update stats
                with self.stats_lock:
                    self.stats['scanned'] += 1
                    if matches:
                        self.stats['with_matches'] += 1
                        self.stats['total_matches'] += len(matches)

                # Show progress every BATCH_SIZE files
                if self.stats['scanned'] % BATCH_SIZE == 0:
                    self.show_progress()

            except Exception as e:
                with self.stats_lock:
                    self.stats['errors'] += 1
            finally:
                self.file_queue.task_done()

    def search_single_file(self, file_path):
        """Search a single file efficiently."""
        matches = []

        try:
            # Fast check for binary files
            if self.is_likely_binary(file_path):
                return matches

            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                for i, line in enumerate(f, 1):
                    if self.stop_event.is_set():
                        break
                    if self.pattern.search(line):
                        # Truncate long lines
                        line_text = line.rstrip('\n\r')
                        if len(line_text) > 200:
                            line_text = line_text[:197] + '...'
                        matches.append((i, line_text))

        except (UnicodeDecodeError, PermissionError, OSError):
            pass

        return matches

    def is_likely_binary(self, file_path):
        """Quick check if file is likely binary."""
        try:
            with open(file_path, 'rb') as f:
                chunk = f.read(1024)
                return b'\x00' in chunk  # Null bytes often indicate binary
        except:
            return False

    def display_worker(self):
        """Display results in real-time."""
        while self.running and not self.stop_event.is_set():
            try:
                file_path, matches = self.result_queue.get(timeout=0.5)

                # Show result
                self.display_result(file_path, matches)

                self.result_queue.task_done()

            except Empty:
                continue
            except:
                break

    def display_result(self, file_path, matches):
        """Display a single search result."""
        with self.print_lock:
            # Get relative path for cleaner display
            try:
                rel_path = os.path.relpath(file_path, self.root_dir)
            except:
                rel_path = file_path

            # Print result
            print(f"\n{Colors.BOLD}{Colors.GREEN}FILE: {rel_path}{Colors.RESET}")
            print(f"{Colors.CYAN}Path: {file_path}{Colors.RESET}")
            print(f"{Colors.YELLOW}Matches: {len(matches)}{Colors.RESET}")
            print(f"{Colors.BLUE}{'─' * 80}{Colors.RESET}")

            for line_num, line_text in matches[:20]:  # Show first 20 matches
                # Highlight search term
                if self.case_sensitive:
                    highlighted = line_text.replace(
                        self.target_word,
                        f"{Colors.RED}{self.target_word}{Colors.RESET}"
                    )
                else:
                    highlighted = self.pattern.sub(
                        f"{Colors.RED}{self.target_word}{Colors.RESET}",
                        line_text
                    )

                print(f"  {Colors.YELLOW}Line {line_num:4d}:{Colors.RESET} {highlighted}")

            if len(matches) > 20:
                print(f"  {Colors.MAGENTA}... and {len(matches) - 20} more matches{Colors.RESET}")

    def show_progress(self):
        """Show search progress."""
        with self.stats_lock:
            scanned = self.stats['scanned']
            total = self.stats['total_files']

            if total > 0:
                percent = (scanned / total) * 100
                elapsed = time.time() - self.stats['start_time']
                remaining = (elapsed / scanned) * (total - scanned) if scanned > 0 else 0

                with self.print_lock:
                    print(f"{Colors.MAGENTA}[*] Progress: {scanned}/{total} ({percent:.1f}%) | "
                          f"Matched: {self.stats['with_matches']} files | "
                          f"ETA: {remaining:.0f}s{Colors.RESET}", end='\r')

    def run(self):
        """Run the search."""

        # Validate
        if not os.path.exists(self.root_dir):
            print(f"{Colors.RED}[!] Directory not found: {self.root_dir}{Colors.RESET}")
            return False

        print(f"\n{Colors.BOLD}Searching for: {Colors.RED}{self.target_word}{Colors.RESET}")
        print(f"Directory: {self.root_dir}")
        print(f"Threads: {self.max_threads}")

        # Collect files
        file_count = self.collect_files_smart()

        if file_count == 0:
            print(f"{Colors.YELLOW}[!] No files found to search{Colors.RESET}")
            return True

        self.stats['start_time'] = time.time()

        print(f"\n{Colors.CYAN}[*] Starting search... (Press Ctrl+C to stop){Colors.RESET}")
        print(f"{Colors.BLUE}{'─' * 60}{Colors.RESET}\n")

        # Start workers
        search_workers = []
        for i in range(self.max_threads):
            t = threading.Thread(target=self.search_worker, args=(i,))
            t.daemon = True
            t.start()
            search_workers.append(t)

        # Start display worker
        display_thread = threading.Thread(target=self.display_worker)
        display_thread.daemon = True
        display_thread.start()

        try:
            # Monitor progress
            while self.running:
                # Check if all files are processed
                if self.file_queue.empty() and self.stats['scanned'] >= self.stats['total_files']:
                    time.sleep(0.5)  # Wait for remaining results
                    break

                self.show_progress()
                time.sleep(0.1)  # Small sleep to prevent CPU hogging

            # Wait for threads to finish
            self.file_queue.join()
            time.sleep(0.5)  # Brief wait for display

        except KeyboardInterrupt:
            print(f"\n\n{Colors.YELLOW}[!] Stopping search...{Colors.RESET}")
            self.stop_event.set()
            self.running = False
            time.sleep(0.5)  # Give threads time to stop

        finally:
            # Final statistics
            self.print_final_summary()

        return True

    def print_final_summary(self):
        """Print final search summary."""
        duration = time.time() - self.stats['start_time']

        print(f"\n\n{Colors.BOLD}{Colors.CYAN}{'═' * 60}{Colors.RESET}")
        print(f"{Colors.BOLD}{Colors.CYAN}FINAL RESULTS{Colors.RESET}")
        print(f"{Colors.BOLD}{Colors.CYAN}{'═' * 60}{Colors.RESET}")

        print(f"\n{Colors.BOLD}Search Statistics:{Colors.RESET}")
        print(f"  Files found:         {self.stats['total_files']:,}")
        print(f"  Files scanned:       {self.stats['scanned']:,}")
        print(f"  Files with matches:  {Colors.GREEN}{self.stats['with_matches']:,}{Colors.RESET}")
        print(f"  Total matches:       {Colors.RED}{self.stats['total_matches']:,}{Colors.RESET}")
        print(f"  Errors:              {self.stats['errors']:,}")

        if duration > 0 and self.stats['scanned'] > 0:
            files_per_sec = self.stats['scanned'] / duration
            print(f"\n{Colors.BOLD}Performance:{Colors.RESET}")
            print(f"  Time:                {duration:.1f} seconds")
            print(f"  Speed:               {files_per_sec:.1f} files/second")

        print(f"\n{Colors.BOLD}Search Term:{Colors.RESET} '{self.target_word}'")

        if self.stats['with_matches'] == 0:
            print(f"\n{Colors.YELLOW}[!] No matches found{Colors.RESET}")
        else:
            print(f"\n{Colors.GREEN}[✓] Search completed!{Colors.RESET}")


def main():
    """Main entry point with simple interface."""

    # 1. Print the Banner first
    print_banner()

    # 2. Simple argument parsing
    if len(sys.argv) > 2:
        directory = sys.argv[1]
        search_term = sys.argv[2]

        # Parse optional arguments
        case_sensitive = '-c' in sys.argv or '--case' in sys.argv
        threads = 32

        for i, arg in enumerate(sys.argv):
            if arg == '-t' and i + 1 < len(sys.argv):
                try:
                    threads = int(sys.argv[i + 1])
                except:
                    pass
    else:
        # Interactive mode
        print(f"{Colors.BOLD}{Colors.CYAN}Interactive Mode{Colors.RESET}")
        print(f"{Colors.BLUE}{'─' * 60}{Colors.RESET}")

        # Get directory
        default_dir = os.getcwd()
        dir_input = input(f"\n{Colors.BOLD}Directory [{default_dir}]: {Colors.RESET}").strip()
        directory = dir_input if dir_input else default_dir

        # Get search term
        while True:
            search_term = input(f"{Colors.BOLD}Search for: {Colors.RESET}").strip()
            if search_term:
                break
            print(f"{Colors.RED}[!] Please enter a search term{Colors.RESET}")

        # Get options
        case_input = input(f"{Colors.BOLD}Case sensitive? (y/N): {Colors.RESET}").strip().lower()
        case_sensitive = case_input == 'y'

        threads = 32

    # Create and run search
    try:
        search = SmartFileSearch(
            root_dir=directory,
            target_word=search_term,
            case_sensitive=case_sensitive,
            max_threads=threads
        )

        search.run()

    except KeyboardInterrupt:
        print(f"\n{Colors.YELLOW}[!] Search interrupted{Colors.RESET}")
    except Exception as e:
        print(f"{Colors.RED}[!] Error: {e}{Colors.RESET}")


if __name__ == "__main__":
    main()
