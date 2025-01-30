def plant_doubling(n):
    r = 0
    while n:
        if n & 1:
            r += 1
        n //= 2
    return r
