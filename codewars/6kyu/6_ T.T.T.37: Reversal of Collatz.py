def reversal_collatz(t, y):
    r = set()
    def f(x, c):
        if c == 0:r.add(x)
        else:
            f(x * 2, c - 1)
            if (x - 1) % 3 == 0 and (x - 1) // 3 % 2: f((x - 1) // 3, c - 1)
    f(y, t)
    return sorted(r)
