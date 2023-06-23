from functools import cache

@cache
def fib_rabbits(n, b):
    if n <= 1: return n
    return fib_rabbits(n - 1, b) + fib_rabbits(n - 2, b) * b