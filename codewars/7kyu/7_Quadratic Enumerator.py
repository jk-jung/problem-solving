def quadratic_gen(a, b, c, start=0, step=1):
    r = []
    for i in range(10):
        x = start + i * step
        y = x * x * a + x * b + c
        yield [x, y]
