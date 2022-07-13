def solve(a, b):
    def f(x):
        x = str(x)
        y = x[::-1]
        for a, b in zip(x, y):
            s1 = '01869'
            s2 = '01896'
            a = s1.find(a)
            b = s2.find(b)
            if a == -1 or a != b:
                return False
        return True

    return sum(1 for x in range(a, b) if f(x))
