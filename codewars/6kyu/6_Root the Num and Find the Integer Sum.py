import math
def root_sum(n):
    r = n
    if n == 1: return 1
    for i in range(2, 50):
        t = int(n ** (1 / i))
        while t ** i < n: t += 1
        if t ** i == n:
            r += t
    return r
