# Smart Threaded File Search Tool

#### Video Demo:  <https://youtu.be/hX7kvbyicW4>

#### Description:

The **Smart Threaded File Search Tool** is a high-performance, command-line utility designed to search for specific text patterns across thousands of files within a directory tree. Unlike standard `grep` or single-threaded search scripts which can be slow on large codebases, this tool leverages Python's `threading` and `queue` modules to perform concurrent scanning. It implements a **Producer-Consumer** architecture to maximize efficiency, allowing file discovery and file searching to happen simultaneously without blocking the user interface.

This project was born out of a need for a tool that is not only fast but also provides better visual feedback than standard command-line tools. It features a real-time progress dashboard, color-coded output for readability, and robust error handling to manage permission issues or binary files gracefully.

### Key Features
* **Multi-Threaded Architecture:** Utilizes up to 32 concurrent threads to scan files, significantly reducing wait times on modern multi-core processors.
* **Smart Binary Detection:** Automatically detects and skips binary files (like images or executables) to prevent read errors and wasted CPU cycles.
* **Real-Time Statistics:** Displays a dynamic status bar showing files scanned, matches found, current speed (files/sec), and estimated time remaining (ETA).
* **ANSI Color Support:** proper highlighting of file paths, line numbers, and matched keywords for instant visual recognition.
* **Safe Resource Management:** Uses thread-safe Queues and Locks to prevent race conditions and data corruption.

### Technical Implementation

The project is structured around a central class, `SmartFileSearch`, which manages the entire lifecycle of the search operation. The logic is divided into three distinct stages:

#### 1. The Producer (File Collection)
The `collect_files_smart` method acts as the "Producer." It traverses the directory tree using `os.walk`. To optimize performance, it filters out known heavy directories (like `.git`, `__pycache__`, or `node_modules`) and ignores files larger than 5MB. Valid file paths are pushed into a thread-safe `file_queue`.

#### 2. The Consumers (Search Workers)
The actual searching is performed by the `search_worker` method. Upon initialization, the program spawns multiple daemon threads (defaulting to 32). Each thread continuously pulls a file path from the `file_queue`, opens it, and scans for the target regex pattern.
- **Regex Compilation:** The search pattern is compiled once at the start using `re.compile()`, making repeated searches highly efficient.
- **Queue Management:** If a match is found, the result is pushed to a separate `result_queue`. This decoupling ensures that the heavy I/O of searching doesn't block the UI.

#### 3. The Display Manager
A separate dedicated thread runs `display_worker`. Its sole job is to pull results from the `result_queue` and print them to the terminal.
- **Thread Safety:** I implemented `threading.Lock()` (specifically `self.print_lock`) to ensure that output from different threads does not interleave or garble the text on the screen.
- **Statistics:** A separate lock (`self.stats_lock`) protects shared counters like `total_files` and `scanned`, ensuring the progress bar remains accurate even when 32 threads update it simultaneously.

### File Structure

- **`project.py`**: The main entry point. It handles argument parsing (switching between Interactive Mode and Command Line Mode) and initializes the `SmartFileSearch` class.
- **`Colors` Class**: A helper class containing ANSI escape sequences. This allows the program to render colored text (Cyan for headers, Green for success, Red for matches) across standard terminal emulators.
- **`README.md`**: This documentation file.

### Challenges and Decisions

One of the main challenges faced during development was **Race Conditions**. Initially, the progress bar would flicker or show incorrect numbers because multiple threads were trying to print to the console and update variables at the exact same time. To solve this, I implemented strict locking mechanisms. The `print_lock` ensures that only one thread can write to stdout at a time, while the `stats_lock` creates a critical section for updating the progress counters.

Another decision was to use **Queues** instead of a simple list. Python's `queue.Queue` is inherently thread-safe, which simplified the logic significantly by removing the need for manual synchronization when adding or removing files from the work list.

### Usage

The tool can be run in two modes:

**1. Interactive Mode:**
Simply run the script without arguments, and it will prompt you for the directory and search term.
```bash
python project.py
