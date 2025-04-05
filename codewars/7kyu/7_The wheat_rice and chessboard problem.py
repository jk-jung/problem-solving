import math
def squares_needed(n):
    r = 0
    while 2 ** r <= n:
        r += 1
    return r
