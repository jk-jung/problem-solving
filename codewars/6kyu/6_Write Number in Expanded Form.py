def expanded_form(n):
    x = 10
    r = []
    while n:
        r = [n % x] + r
        n -= n % x
        x *= 10
    return ' + '.join(str(x) for x in r if x)
