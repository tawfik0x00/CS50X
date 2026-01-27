from cs50 import get_int, get_string
from sys import exit


def main():
    credit_number = get_credit("Number: ")

    if credit_number == 1:
        print("INVALID")
        exit(1)

    result = check_sum(credit_number)
    if (result != 0):
        print("INVALID")
        exit(2)

    print_type(credit_number)


def check_sum(number):
    sum1 = 0
    sum2 = 0

    while number != 0:
        # Get the last digit
        last_digit = number % 10
        number = number // 10
        sum1 += last_digit

        # Get the second last digit
        if number != 0:
            second_last = number % 10
            number = number // 10

            second_last *= 2
            if second_last > 9:
                second_last -= 9
            sum2 += second_last

    return (sum1 + sum2) % 10


# Get the Credit Card Number
def get_credit(prompt):
    cn = get_int(prompt)
    cn_len = len(str(cn))

    # Check the length
    if cn_len not in [13, 15, 16]:
        return 1
    return cn


# Luhan check algorithm
def print_type(number):

    number = str(number)
    if number[0] == '4' and len(number) in [13, 16]:
        print("VISA")
    elif number[:2] in ['51', '52', '53', '54', '55'] and len(number) == 16:
        print("MASTERCARD")
    elif number[:2] in ['34', '37'] and len(number) == 15:
        print("AMEX")
    else:
        print("INVALID")


main()
