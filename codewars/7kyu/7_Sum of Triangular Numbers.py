def sum_triangular_numbers(n):
    r, t = 0, 0
    for i in range(n):
        t += i + 1
        r += t
    return r
