from functools import cache

@cache
def fibfusc(n):
    if n == 0: return (1, 0)
    if n == 1: return (0, 1)
    x, y = fibfusc(n // 2)
    if n % 2:
        return (-y*(2*x + 3*y), (x + 2*y)*(x + 4*y))
    return ((x + y)*(x - y), y*(2*x + 3*y))