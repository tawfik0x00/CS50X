from cs50 import get_int


def get_height(prompt):
    try:
        while True:
            height = get_int(prompt)
            if height >= 1 and height <= 8:
                return height
    except ValueError:
        pass


# get the height of the pyramid
height = get_height("Height: ")

# start print the pyramid
for i in range(1, height + 1):
    print(" " * (height - i), end='')
    print("#" * i, end='')
    print("  ", end='')
    print("#" * i)
