def count_presents(v, p):
    def f(x):
        t = list(map(int, x.split(':')))
        return t[0] * 3600 + t[1] * 60 + t[2]
    s = sorted([f(x) for x in p])
    t = sum(v.values()) * 24 * 3600
    r = 0
    while len(s) and s[0] <= t:
        r += 1
        t -= s.pop(0)
    return r
