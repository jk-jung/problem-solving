import math


def get_sum(x):
    m = int(math.sqrt(x))

    s = 0
    for i in range(2, m + 1):
        if x % i == 0:
            s += i
            if i != x / i: s += x // i
    return s


def calc(x):
    s = get_sum(x)
    if s > x and get_sum(s) == x:
        return s
    return None


def buddy(start, limit):
    for x in range(start, limit + 1):
        r = calc(x)
        if r:
            return [x, r]
    return "Nothing"
