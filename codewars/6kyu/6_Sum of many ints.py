def f(n, m):
    def f(x): return x * (x + 1) // 2
    return n // m * f(m - 1) + f(n % m)
