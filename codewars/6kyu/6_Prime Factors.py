def prime_factors (n):
    i = 2
    r = []
    while i * i <= n:
        while n % i == 0:
            r.append(i)
            n //= i
        i += 1
    if n > 1: r.append(n)
    return r