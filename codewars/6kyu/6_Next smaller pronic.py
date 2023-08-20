import math
def next_smaller_pronic(n):
    t = int(n ** .5)
    while t * (t + 1) < n: t += 1
    return t * (t - 1)
