from cs50 import get_string

# Get the text from the user
text = get_string("Text: ")

# count the number of words
words = len(text.split())

# count the number of sentences and letters
sentences = 0
letters = 0

for c in text:
    if c.isalpha():
        letters += 1
    if c in ['.', '?', '!']:
        sentences += 1

# formula
L = (letters / words) * 100
S = (sentences / words) * 100

result = round(0.0588 * L - 0.296 * S - 15.8)

if result >= 16:
    print("Grade 16+")
elif result < 1:
    print("Before Grade 1")
else:
    print(f"Grade {result}")
