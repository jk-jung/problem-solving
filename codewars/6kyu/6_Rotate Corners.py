def rotate_corners(v):
    def f(x):
        if x is True: return 1
        if x is False: return 0
        if isinstance(x, str): return ord(x)
        return x

    t = [v[0][0], v[0][-1], v[-1][-1], v[-1][0]]
    l = sum(map(f, t))
    k = sum(sum(map(f, x)) for x in v)
    n = (4 - (k - l) * l % 4)
    t = (t + t + t)[n:n + 4]
    return [[t[0], t[1]], [t[3], t[2]]]

