import csv

with open("favorites.csv") as file:
    reader = csv.reader(file) # its return an object of lines
    next(reader)
    for row in reader:
        print(row) # each row is a list of strings each filed saved as element in the list
        
