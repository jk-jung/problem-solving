def is_hollow(v):
    def f(t):
        c = 0
        while len(t) and t[0] != 0: c, t = c + 1, t[1:]
        return c, t
    c1, v = f(v)
    c2, v = f(v[::-1])

    return c1 == c2 and len(v) >= 3 and set(v) == {0}
