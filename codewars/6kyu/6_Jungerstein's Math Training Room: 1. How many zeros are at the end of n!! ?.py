def count_zeros_n_double_fact(n):
    if n % 2: return 0
    r, b = 0, 10
    while b <= n:
        r += n // b
        b *= 5
    return r
