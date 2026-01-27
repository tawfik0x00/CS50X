from cs50 import get_string

answer = get_string("what's your name? ")
print("hello, " + answer)
print(f"hello, {answer}")
print("hello, {}".format(answer))
