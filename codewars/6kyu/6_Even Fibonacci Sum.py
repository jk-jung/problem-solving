def even_fib(m):
    r, a, b = 0, 0, 1
    while a < m:
        r += 0 if a % 2 else a
        a, b = b, a + b
    return r