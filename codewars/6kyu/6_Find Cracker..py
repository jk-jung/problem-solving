def find_hack(v):
    def f(t):
        g = {'A': 30, 'B': 20, 'C': 10, 'D': 5}
        s = sum(g.get(x, 0) for x in t[2])
        if len(t[2]) >= 5 and all(g.get(x, 0) >= 20 for x in t[2]): s += 20
        return min(200, s) != t[1]

    return [x[0] for x in v if f(x)]
