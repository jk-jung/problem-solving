from math import lcm
def find_us(n1, n2, k, p, d):
    l = 1
    for x in p: l = lcm(x, l)
    s = (n1 + l - 1) // l * l

    d = set(''.join(map(str, d)))
    r = []
    for x in range(s, n1 + n2 * k + 1, l):
        if set(str(x)) & d == d:
            r.append(x)

    return r
