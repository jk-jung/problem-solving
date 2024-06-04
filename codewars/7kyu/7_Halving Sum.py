def halving_sum(n):
    r = n
    t = 2
    while n // t > 0:
        r += n // t
        t *= 2
    return r