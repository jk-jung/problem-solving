def faulty_odometer(n):
    r, s, b = 0, '012356789', 1
    while n:
        r += s.index(str(n%10)) * b
        n //= 10
        b *= 9
    return r
