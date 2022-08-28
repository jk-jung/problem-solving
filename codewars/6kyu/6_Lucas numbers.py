from functools import cache
import sys
sys.setrecursionlimit(10**7)

@cache
def lucasnum(n):
    if n == 0: return 2
    if n == 1: return 1
    if n > 0: return lucasnum(n - 1) + lucasnum(n - 2)
    else: return lucasnum(n + 2) - lucasnum(n + 1)