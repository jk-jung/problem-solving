def nbMonths(a, b, save, loss):
    s, i = 0, 0
    while True:
        if a + s >= b:
            return [i, round(a + s - b)]

        i += 1
        if i % 2 == 0:
            loss += .5

        b = b * (100 - loss) / 100
        a = a * (100 - loss) / 100
        s += save
