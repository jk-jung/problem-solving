def height(n):
    r = 2000000
    t = r
    for i in range(n):
        t /= 2.5
        r += t
    return '%.03f' % r
