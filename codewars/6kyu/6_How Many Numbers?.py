def sel_number(n, d):
    def f(x):
        s = list(map(int, str(x)))
        return all(0 < b - a <= d for a, b in zip(s, s[1:]))
    return sum(f(i) for i in range(12, n + 1))
