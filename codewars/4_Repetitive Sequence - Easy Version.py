def find(n):
    if n <= 3: return min(n, 2)
    if n <= 5: return 3
    d = [1, 1, 2, 2]

    idx = 4
    n -= 5
    for k in range(3, 10000000):
        c = k * d[k]

        if c >= n:
            return idx + (n - 1) // k
            pass
        else:
            n -= c
        idx += d[k]
        if len(d) < 1000000:
            d += [k] * d[k]