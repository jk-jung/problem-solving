from functools import cache
import sys
sys.setrecursionlimit(10**7)

@cache
def f(n):
    if n <= 2: return 1
    return f(n - f(n - 1)) + f(n - f(n - 2))

def hofstadter_Q(n):
    return f(n)
