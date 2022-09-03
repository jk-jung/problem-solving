from math import ceil

def solve(n):
    for i in range(5000, 0, - 1):
        x = int((n - i * i ) / 2 / i)
        if x > 0 and (x + i) ** 2 - x ** 2 == n:
            return x * x
    return -1