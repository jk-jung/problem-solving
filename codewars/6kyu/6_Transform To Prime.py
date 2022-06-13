def minimum_number(v):
    x = sum(v)
    for i in range(1000):
        j, y = 2, x + i
        ok = True
        while j * j <= y:
            if y % j == 0:
                ok = False
                break
            j += 1
        if ok:
            return i
