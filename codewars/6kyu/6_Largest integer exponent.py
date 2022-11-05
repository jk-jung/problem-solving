def get_exponent(n, p):
    if p <= 1: return None
    x = 0
    while n % p ** (x + 1) == 0:
        x += 1
    return x
