def three_split(v):
    n = len(v)
    s = sum(v)
    if s % 3: return 0
    s //= 3

    d = [0 for _ in range(n)]

    d[0] = v[0]
    for i in range(1, n):
        d[i] = d[i-1] + v[i]


    r = 0
    for i in range(n):
        if d[i] != s:
            continue
        for j in range(i + 1, n - 1):
            if d[j] - d[i] == s:
                r += 1
    return r