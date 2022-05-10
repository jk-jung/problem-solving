def step(g, m, n):
    def f(x):
        i = 2
        while i * i <= x:
            if x % i == 0: return False
            i += 1
        return True
    for i in range(m, n - g):
        if f(i) and f(i + g):
            return [i, i + g]
    return None
