def sol_equa(n):
    r = []
    m = int(n ** .5 + 1e-9)
    for a in range(1, m + 1):
        if n % a == 0:
            dif = n // a - a
            if dif % 4 != 0: continue
            y = dif // 4
            x = a + 2 * y
            r.append([x, y])
    return r
    