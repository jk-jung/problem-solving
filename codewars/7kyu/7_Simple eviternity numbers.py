from collections import Counter
from functools import cache

@cache
def f(x):
    c = Counter(str(x))
    return c['8'] >= c['5'] >= c['3'] and c['8'] + c['5'] + c['3'] == len(str(x))
def solve(a, b):


    return len([x for x in range(a, b) if f(x)])
