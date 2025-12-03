from functools import cache

LIMIT = 1000
d = {}

POWERS = [(10**i, 10 ** (i + 1)) for i in range(22)]


@cache
def next_state(t):
    if t == 0:
        return 0, 0, 0
    for s, e in POWERS:
        if s <= t < e:
            x = t // s
            nxt = t % s
            return x, nxt, x * s


def go(up, remain):
    if remain < 10:
        return (0, 0) if remain == 0 and up == 0 else (1, -up)

    key = (up, remain)
    if key in d:
        return d[key]

    r = 0
    while remain >= 0:
        if up == 0 and remain == 0:
            break
        x, nxt, remain = next_state(remain)
        a, b = go(up + x, nxt)
        r += a
        remain += b

    d[key] = (r, remain)
    return (r, remain)


def f(x):
    return go(0, x)[0]


def jump_to_zero(arr):
    return [f(x) for x in arr]
