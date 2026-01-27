import csv

file = open("phonebook.csv", "a")

name = input("Name: ")
number = input("Number: ")

# Print to file
writer = csv.writer(file)
writer.writerow([name, number])

file.close()
