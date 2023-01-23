def fractalize(v, c):
    if len(v[0]) == 0: return []
    o = v
    while c > 1:
        n, m = len(v), len(v[0])
        e = ['.' * m for i in range(n)]
        t = [[v if o[i][j] == '*' else e for j in range(len(o[0]))] for i in range(len(o))]
        r = []
        for i in range(len(o)):
            for j in range(n):
                r.append(''.join(x[j] for x in t[i]))
        v = r
        c -= 1
    return v
