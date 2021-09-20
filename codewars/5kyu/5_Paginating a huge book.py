def page_digits(n):
    r = 0
    m = 9
    while n > 0:
        r += max(n, 0)
        n -= m
        m *= 10
    return r