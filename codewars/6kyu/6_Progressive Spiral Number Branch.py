def branch(n):
    if n == 1: return 0
    t = int((1 + (n-1)**.5) // 2 + 1) * 2 - 1
    n -= (t - 2) ** 2
    return (n - 1) // (t - 1)
