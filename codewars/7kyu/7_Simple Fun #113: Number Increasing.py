from functools import cache
import sys
sys.setrecursionlimit(10**7)

@cache
def number_increasing(n):
    if n == 1: return True
    if n < 1: return False
    if n % 3 == 0 and number_increasing(n // 3): return True
    return number_increasing(n - 5)
    