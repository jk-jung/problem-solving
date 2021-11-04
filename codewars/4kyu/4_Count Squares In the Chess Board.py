def count(v):
    n = len(v)
    d = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

    r = {}
    for i in range(n):
        for j in range(n):
            if v[i][j]:
                d[i + 1][j + 1] = d[i + 1][j] + 1

                cur = d[i + 1][j + 1]
                for k in range(2, i + 2):
                    cur = min(cur, d[i - k + 2][j + 1])
                    if cur < k: break
                    if k not in r: r[k] = 0
                    r[k] += 1
    return r