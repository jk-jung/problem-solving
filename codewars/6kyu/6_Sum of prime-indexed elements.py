def total(a):
    r = 0
    for i in range(2, len(a)):
        y, x = i, 2
        ok = True
        while x * x <= y:
            if y % x == 0:
                ok = False
                break
            x += 1
        if ok:
            r += a[i]
    return r