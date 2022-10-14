from math import factorial
from collections import Counter
def sum_arrangements(n):
    n = str(n)
    c = Counter(map(int, n))
    r = 0
    x = (10 ** len(n) - 1) // 9

    f = factorial(len(n) - 1)
    for i in range(1, 10):
        r += f * i * c[i] * x
    return r
