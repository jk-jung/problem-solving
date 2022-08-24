from math import log


def compare_powers(a, b):
    a = log(a[0]) * a[1]
    b = log(b[0]) * b[1]

    if a == b: return 0
    return 1 if a < b else -1
