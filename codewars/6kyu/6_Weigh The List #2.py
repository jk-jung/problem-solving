def weigh_the_list(v):
    a, b = v[0], sum(v[1:])
    if b == 0:
        b = v[-1]
        return [-b] + [a] * (len(v) - 2) + [a + a]
    return [-b] + [a] * (len(v) - 1)
