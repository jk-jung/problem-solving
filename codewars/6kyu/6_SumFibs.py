def sum_fibs(n):
    r, a, b = 0, 0, 1
    for i in range(n):
        a, b = b, a + b
        if a % 2 == 0:
            r += a
    return r