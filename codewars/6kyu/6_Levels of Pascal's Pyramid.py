from functools import cache

@cache
def pascal_pyr_layer(n):
    if n == 1: return [[1]]
    t = pascal_pyr_layer(n - 1)
    r = []
    def ck(y, x):
        if y < 0 or y >= len(t): return 0
        if x < 0 or x >= len(t[y]): return 0
        return t[y][x]
    for i in range(0, n):
        v = []
        for j in range(0, i + 1):
            x = ck(i - 1, j) + ck(i - 1, j - 1) + ck(i, j)
            v.append(x)
        r.append(v)
    return r
