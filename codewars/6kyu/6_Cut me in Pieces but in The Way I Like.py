from functools import cache

@cache
def part_const(n, k, num, first=True):
    if n < 0: return 0
    if k == 1: return 0 if n == num else 1

    r = 0
    for i in range(1 if first else 0, n + 1):
        if i == num: continue
        r += part_const(n - i * k, k - 1, max(-1, num - i), False)
    return r
