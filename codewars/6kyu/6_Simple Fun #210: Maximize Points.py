def maximize_points(b, a):
    a = sorted(a)
    b = sorted(b)
    r = 0
    for x in a:
        while b and b[0] <= x: b.pop(0)
        if b:
            r += 1
            b.pop(0)
    return r
