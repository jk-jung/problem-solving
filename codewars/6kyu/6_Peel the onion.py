from functools import cache

@cache
def peel_the_onion(s, d):
    if s == 0: return []
    if s == 1: return [1]
    r = peel_the_onion(s - 2, d)
    return [s ** d - sum(r)] + peel_the_onion(s - 2, d)
