def candles(a, b):
    r = 0
    a = a * b
    while a >= b:
        t = a // b
        r += t
        a = a % b + t
    return r
