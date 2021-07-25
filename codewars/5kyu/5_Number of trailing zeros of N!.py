def zeros(n):
    r = 0;
    while n:
        n //= 5
        r += n
    return r