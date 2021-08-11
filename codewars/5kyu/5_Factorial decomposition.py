def decomp(n):
    r = {}
    for x in range(2, n + 1):
        f = 1
        for y in r:
            if x % y == 0:
                f = 0
                break
        if not f: continue

        k = x
        r[x] = 0
        while k <= n:
            r[x] += n // k
            k *= x

    return ' * '.join(f"{k}{f'^{v}' if v > 1 else ''}" for k, v in r.items())
