def divisions(n, d):
    r = 0
    while n:
        n //= d
        r += 1
    return r - 1
