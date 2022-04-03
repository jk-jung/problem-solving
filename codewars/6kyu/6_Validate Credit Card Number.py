def validate(n):
    r, c = 0, 0
    while n:
        k = n % 10 * (2 if c % 2 else 1)
        r += k if k < 10 else k - 9
        n //= 10
        c ^= 1
    return r % 10 == 0