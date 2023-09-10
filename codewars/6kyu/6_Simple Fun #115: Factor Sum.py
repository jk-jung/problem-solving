def factor_sum(n):
    r = 0
    m = n
    for i in range(2, n + 1):
        while n % i == 0:
            n //= i
            r += i
    if r == m: return r
    return factor_sum(r)
