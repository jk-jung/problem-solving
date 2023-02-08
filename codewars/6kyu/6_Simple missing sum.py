def solve(v):
    v = sorted(v)
    d = [1 if _ in v else 0 for _ in range(sum(v) + 2)]
    d[0] = 1
    s = 0
    for x in v:
        for i in range(s, -1, -1):
            if d[i]: d[i + x] = 1
        s += x
    for i in range(s + 2):
        if not d[i]: return i