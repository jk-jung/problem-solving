def longest_comb(v, cmd):
    n = len(v)
    r = [[]]

    d = [0 for _ in range(n + 1)]
    for i in range(n):
        d[i + 1] = 1
        for j in range (i):
            if (cmd[0] == '>' and v[i] < v[j]) or (cmd[0] == '<' and v[i] > v[j]):
                d[i + 1] = max(d[i + 1], d[j + 1] + 1)
    vv = max(d)
    if vv < 3: return []

    for st in range(1 << n):
        t = [(i, x) for i, x in enumerate(v) if st >> i & 1]
        if len(t) != vv: continue

        ok = True
        for i in range(1, len(t)):
            if cmd[0] == '>' and t[i][1] >= t[i-1][1]: ok = False
            if cmd[0] == '<' and t[i][1] <= t[i-1][1]: ok = False

        if ok:
            if len(t) == len(r[0]):
                r.append(t)
            elif len(t) > len(r[0]):
                r = [t]

    r = [[x[1] for x in y] for y in sorted(r)]
    return r if len(r) > 1 else r[0]