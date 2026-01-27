from cs50 import get_float

# First get the cents


def get_cents(prompt):
    while True:
        cents = get_float(prompt)

        if (cents < 0.00):
            pass
        else:
            return int(cents * 100)

# like c in pset1 but math solve in best way

# def calc_quarters(cents):
#     quarters = 0
#     while cents >= 25:
#         cents -= 25
#         quarters += 1
#     return quarters


# def calc_dimes(cents):
#     dimes = 0
#     while cents >= 10:
#         cents -= 10
#         dimes += 1
#     return dimes


# def calc_nickels(cents):
#     nickels = 0
#     while cents >= 5:
#         cents -= 5
#         nickels += 1
#     return nickels


# def calc_pennies(cents):
#     pennies = 0
#     while cents >= 1:
#         cents -= 1
#         pennies += 1
#     return pennies


cents = get_cents("Change: ")

quarters = cents // 25
cents %= 25

dimes = cents // 10
cents %= 10

nickels = cents // 5
cents %= 5

pennies = cents // 1
cents %= 1

print(quarters + dimes + nickels + pennies)
