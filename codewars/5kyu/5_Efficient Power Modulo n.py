def power_mod(x, y, n):
    r = 1
    while y:
        if y & 1: r = r * x % n
        y //= 2
        x = x * x % n
    return r