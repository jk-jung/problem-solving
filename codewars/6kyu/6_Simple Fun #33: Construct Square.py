from collections import Counter
from functools import cache

@cache
def f(i):
    return [x[1] for x in Counter(str(i * i)).most_common()]

def construct_square(s):
    c = [x[1] for x in Counter(s).most_common()]
    for i in range(100000, 0, -1):
        if c == f(i):
            return i * i
    return -1
