def solve(n):
    n = str(n)
    r = 1 << 30
    m = len(n)
    for i in range(m):
        for j in range(m):
            if i == j: continue
            t = ''.join(x for k, x in enumerate(n) if k not in (i, j)) + n[i] + n[j]
            c = 0
            if t[0] == '0':
                for k in range(m):
                    if t[k] != '0':
                        t = list(t)
                        t[0], t[k] = t[k], t[0]
                        t = ''.join(t)
                        c = k
                        break
            if int(t) % 25 == 0 and len(str(int(t))) == m:
                r = min(r, m - j - 1 + m - i - 1 + (-1 if i < j else 0) + c)

    if r == (1 << 30): r =-1
    return r
