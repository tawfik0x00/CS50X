import csv

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter() # object have counting capabilites

    for row in reader:
        favorite = row['problem']
        counts[favorite] += 1

for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
