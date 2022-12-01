def mult_triangle(n):
    m = n * (n + 1) // 2
    t = ((n + 1) // 2) ** 2
    return [m ** 2, m ** 2 - t ** 2, t ** 2]
