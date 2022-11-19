def solve(v):
    def f(x):
        a, b = 0, 0
        while x % 3 == 0: x, a = x // 3, a + 1
        while x % 2 == 0: x, b = x // 2, b + 1
        return (-a, b)

    return sorted(v, key=f)
