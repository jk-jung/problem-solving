def f(k, n):
    d = [1 for _ in range(n + 1)]
    for i in range(1, n + 1):
        d[i] = d[i - 1] + d[i // k]
    return d[n]