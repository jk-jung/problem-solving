from functools import cache

@cache
def three_details(n):
    if n < 3: return 0
    if n == 3: return 1
    a = n // 2
    b = n - a
    return three_details(a) + three_details(b)
  