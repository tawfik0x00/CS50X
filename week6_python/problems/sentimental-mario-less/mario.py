def get_height(prompt):
    while True:
        try:
            height = int(input(prompt))
            if height >= 1 and height <= 8:
                return height
        except ValueError:
            pass


# get the height of the pyramid
height = get_height("Height: ")

# start print the pyramid
for i in range(1, height + 1):
    print(" " * (height - i), end='')
    print("#" * i)
