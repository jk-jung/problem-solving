def closest_points(v):
    v.sort()
    n = len(v)
    r, rl = None, []
    for i in range(n):
        for j in range(i + 1, n):
            t = (v[i][0] - v[j][0]) ** 2 + (v[i][1] - v[j][1]) ** 2

            if r is None or t < r:
                r = t
                rl = [[v[i], v[j]]]
            elif t == r:
                rl.append([v[i], v[j]])

    return [n, rl, round(r ** .5, 4)]
