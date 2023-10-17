def riemann_trapezoidal(f, n, a, b):
    r, d = 0, (b - a) / n
    for i in range(n):
        x = a + d * i
        y = x + d
        r += (f(y) + f(x)) * d / 2
    return round(r * 100) / 100
