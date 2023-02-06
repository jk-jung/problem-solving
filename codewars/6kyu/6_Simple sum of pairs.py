def solve(n):
    if n < 10: return n
    t = 9
    while t * 10 + 9 < n: t = t * 10 + 9
    def f(x): return sum(map(int, str(x)))
    return f(n - t) + f(t)
