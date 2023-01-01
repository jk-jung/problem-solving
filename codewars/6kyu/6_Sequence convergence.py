def convergence(n):
    def f(x):
        if x < 10: return x * 2
        r = 1
        for y in str(x):
            if int(y): r *= int(y)
        return x + r

    r = 0
    a = 1
    b = n
    while a != b:
        while a < b: a = f(a)
        if a == b: return r
        b = f(b)
        r += 1
    return r
