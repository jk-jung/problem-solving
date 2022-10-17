def solve(n):
    def f(x):
        i = 2
        while i * i <= x:
            if x % i == 0: return False
            i += 1
        return True

    if f(n): return n
    for i in range(1, 100):
        if f(n - i): return n - i
        if f(n + i): return n + i
        