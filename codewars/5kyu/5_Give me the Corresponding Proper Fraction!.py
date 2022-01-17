from heapq import *
from math import gcd


def f(d_max, pos):
    print(d_max, pos)
    if pos == 0: return '1/1'

    q = []
    last = d_max

    heappush(q, (-(last - 1) / last, last - 1, last))
    last -= 1

    used = {}
    r = ''
    while pos > 0 and len(q) > 0:
        f, a, b = heappop(q)
        if f not in used:
            pos -= 1

        used[f] = 1
        if last >= 2 and -f < (last - 1) / last:
            heappush(q, (-(last - 1) / last, last - 1, last))
            last -= 1

        if a > 1:
            heappush(q, (-(a-1) / b, a - 1, b))

    r = f'{a // gcd(a, b)}/{b // gcd(a, b)}'
    if pos > 0: r = '-1'
    return r


# def f(d_max, n):
#     """Calculate the nth element of
#        d_max-th Farey sequence in descending order."""
#     a, b, c, d = 1, 1, d_max-1, d_max
#     for _ in range(n):
#         if a == 0: break
#         k = (d_max + b) // d
#         a, b, c, d = c, d, (k*c-a), (k*d-b)
#     return f"{a}/{b}" if a else "-1"
