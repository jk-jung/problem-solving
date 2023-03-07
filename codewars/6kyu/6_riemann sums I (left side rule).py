def left_riemann(f, n, a, b):
    r, d = 0, (b - a) / n
    for i in range(n):
        r += f(a + d * i) * d
    return r
