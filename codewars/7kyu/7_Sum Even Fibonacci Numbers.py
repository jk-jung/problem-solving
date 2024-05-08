def sum_even_fibonacci(limit):
    a, b = 1, 2
    r = 0
    while a <= limit:
        if a % 2 == 0: r += a
        a, b = b, a + b
    return r
