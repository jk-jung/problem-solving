def mystery(s, n):
    n = bin(n)[2:]
    return ''.join(y for x, y in zip(n, s) if x == '1')
