def count_nines(n):
    s = str(n)
    base = 10
    r = 0
    while base <= n * 10:
        x = n // base
        y = n % base // (base // 10)
        z = n % (base // 10)

        r += x * (base // 10)
        if y == 9: r += z + 1
        base *= 10

    return r
