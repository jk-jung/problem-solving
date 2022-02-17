def dig_pow(n, p):
    r = sum(int(x) ** (i+p) for i, x in enumerate(str(n)))
    return -1 if r % n else r // n
