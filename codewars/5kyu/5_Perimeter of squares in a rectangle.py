def perimeter(n):
    r = 0
    a, b = 1, 1

    for i in range(n + 1):
        r += a * 4
        a, b = b, a + b
    return r
