def no_adjacent_subsequences(v):
    r = []
    def f(i=-2, t = []):
        r.append(t)
        i += 2
        while i < len(v):
            f(i, t + [v[i]])
            i += 1
    f()
    return sorted(r)
