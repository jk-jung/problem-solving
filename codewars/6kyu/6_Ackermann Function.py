from functools import lru_cache

@lru_cache()
def Ackermann(m, n):
    if m == 0: return n + 1
    elif n == 0: return Ackermann(m - 1, 1)
    return Ackermann(m - 1, Ackermann(m, n - 1))