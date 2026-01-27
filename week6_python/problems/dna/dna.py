import csv
from sys import argv


def main():

    # First we need to check the command line
    if len(argv) != 3:
        print(f"{argv[0]} file.csv file.txt")
        return 1

    # we need to open the csv file
    with open(argv[1]) as csvfile:
        csvreader = csv.DictReader(csvfile)
        profiles = list(csvreader)

    # we need to read dna sequence
    with open(argv[2]) as dnafile:
        dna_sequence = dnafile.read()

    # find longest math for each STR
    str_counts = {}  # here with every str name will save the number of matches
    # the str keys to save repeats and omiting name key
    str_names = list(profiles[0].keys())[1:]

    # count each str name in the sequence and save its values
    for str_name in str_names:
        str_counts[str_name] = longest_match(dna_sequence, str_name)

    # we need to determine which the profile is accurate this str_counts dict
    for profile in profiles:
        match = True
        for str_name in str_names:
            # This will run if the profile any str not equal the number of str in str_counts
            if int(profile[str_name]) != str_counts[str_name]:
                match = False  # for the first profile
                break

        # if true run this if this profile is ok run
        if match:
            print(profile['name'])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
