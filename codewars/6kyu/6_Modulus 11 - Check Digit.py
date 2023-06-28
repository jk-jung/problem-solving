from itertools import cycle

def add_check_digit(n):
    a = cycle([2, 3, 4, 5, 6, 7])
    r = sum(x * int(y) for x, y in zip(a, n[::-1])) % 11
    return n + ('X' if r == 1 else str((11 - r) % 11))
