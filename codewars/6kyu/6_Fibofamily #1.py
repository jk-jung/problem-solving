from functools import cache

@cache
def P(n):
    if n == 0: return 7
    if n == 1: return 31
    return (1 + P(n - 1)) * (1 + P(n - 2)) - 1

t = [P(i) % 9 for i in range(24)]

def G(n):
    return t[n % len(t)]
