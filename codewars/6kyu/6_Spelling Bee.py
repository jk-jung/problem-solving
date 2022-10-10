def how_many_bees(v):
    if not v or len(v) == 0: return 0
    n, m = len(v), len(v[0])
    r = 0
    def calc():
        nonlocal r
        for i in range(n):
            for j in range(m):
                if ''.join(v[i][j:j + 3]) == 'bee':
                    r += 1
                if i + 2 < n and v[i][j] == 'b' and v[i + 1][j] == 'e' and v[i + 2][j] == 'e':
                    r += 1
    calc()
    v = [x[::-1] for x in v[::-1]]
    calc()
    return r
