from functools import cache

@cache
def padovan(n):
    if n <= 2: return 1
    return padovan(n - 2) + padovan(n - 3)
