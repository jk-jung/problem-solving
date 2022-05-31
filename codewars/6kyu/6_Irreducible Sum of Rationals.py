from math import lcm, gcd


def sum_fracts(v):
    if not v:
        return
    l = lcm(*[x[1] for x in v])

    t = 0
    for x, y in v:
        t += x * l // y

    g = gcd(t, l)
    t //= g
    l //= g
    if t % l == 0:
        return t // l
    return [t, l]