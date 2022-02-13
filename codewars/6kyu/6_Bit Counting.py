def count_bits(n):
    r = 0
    while n: r, n = r + n % 2, n // 2
    return r