def prime_factors(n):
    k = 2
    r = []
    while n != 1:
        c = 0
        while n % k == 0:
            c += 1
            n //= k
        if c > 0:r.append((k, c))
        k += 1

    return ''.join(f'({x[0]}{f"**{x[1]}" if x[1] > 1 else ""})' for x in r)