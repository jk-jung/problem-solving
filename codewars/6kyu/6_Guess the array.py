def guess(f, n):
    v = [0 for _ in range(n)]
    v[0] = (f(0, 1) + f(0, 2) - f(1, 2)) // 2
    for i in range(1, n):
        v[i] = f(i, i - 1) - v[i - 1]
    return v
