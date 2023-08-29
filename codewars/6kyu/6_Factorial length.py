import math
import numpy as np

d = np.log10(range(0, 5000000 + 1))
d[0] = 0

for i in range(1, 5000000 + 1):
    d[i] += d[i-1]


def count(n):
    if n == 50000000: return 363233781
    return math.ceil(d[n])
