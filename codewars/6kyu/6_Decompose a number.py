def decompose(n):
    r, x = [], 2
    while x ** 2 <= n:
        t = 2
        while x ** (t + 1) <= n: t += 1
        n -= x ** t
        r.append(t)
        x += 1
    return [r, n]