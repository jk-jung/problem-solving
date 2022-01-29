def closest_points3D(v):
    v.sort()
    n = len(v)
    r, rl = None, []
    for i in range(n):
        for j in range(i + 1, n):
            t = sum((v[i][k] - v[j][k]) ** 2 for k in range(3))

            if r is None or t < r:
                r = t
                rl = [[v[i], v[j]]]
            elif t == r:
                rl.append([v[i], v[j]])

    return [n, rl, round(r ** .5, 5)]
