def square_digits(s):
    return int("".join(str(int(x) ** 2) for x in str(s)))