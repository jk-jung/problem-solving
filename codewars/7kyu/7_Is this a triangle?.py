def is_triangle(a, b, c):
    a, b, c = sorted([a, b, c])
    return a > 0 and (a + b > c)
