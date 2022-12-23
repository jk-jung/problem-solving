from functools import cache

@cache
def f(n, cur=1, last=-1):
    if cur == n + 1: return 0 if last == -1 else 1
    r = f(n, cur + 1, last)
    if cur > last + 1: r += f(n, cur + 1, cur)
    return r
