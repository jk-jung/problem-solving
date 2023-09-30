def bin_mul(m,n):
    if m < n: m, n = n, m
    r = []
    while m and n:
        if m % 2: r.append(n)
        m //= 2
        n *= 2
    return r[::-1]
