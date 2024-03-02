def two_count(n):
    r = 0
    while n % 2 == 0:
        n //= 2
        r += 1
    return r
