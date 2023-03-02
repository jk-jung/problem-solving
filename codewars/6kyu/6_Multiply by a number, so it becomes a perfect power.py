def mul_power(n, k):
    r, z = [], 1
    for i in range(2, int(n ** .5)):
        c = 0
        while n % i == 0:
            c = (c + 1) % k
            n //= i
        if c :
            z *= i ** (k - c)
    if n != 1:
        z *= n ** (k - 1)
    return z
