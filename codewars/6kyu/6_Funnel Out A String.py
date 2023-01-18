def funnel_out(v):
    n, m = len(v), len(v[0])
    r = ''

    def f(y, x):
        if y > 0:
            if v[y-1][x] <= v[y-1][x + 1]:
                c = f(y - 1, x)
            else:
                c = f(y - 1, x + 1)
        else:
            c = '가'
        t = v[y][x]
        v[y][x] = c
        return t

    while True:
        k = f(n - 1, 0)
        if k == '가': break
        r += k
    return r
