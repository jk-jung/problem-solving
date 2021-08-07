def lcs(x, y):
    n = len(x)
    r = ''
    for i in range(1 << n):
        s = ''
        for k in range(n):
            if i >> k & 1: s += x[k]

        p = 0
        for k in y:
            if p < len(s) and s[p] == k:
                p += 1

        if p == len(s) and len(s) > len(r): r = s

    return r
