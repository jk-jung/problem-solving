def mobius(n):
    i = 2
    t = 0
    while i * i <= n:
        c = 0
        while n % i == 0:
            c += 1
            n //= i
        if c >= 2: return 0
        if c > 0: t += 1
        i += 1
    if n != 1: t += 1
    return 1 if t % 2 == 0 else -1
