def number_of_carries(a, b):
    a = str(a)[::-1] + '0' * 100
    b = str(b)[::-1] + '0' * 100

    r, c = 0, 0
    for x, y in zip(a, b):
        t = c + int(x) + int(y)
        c = t // 10
        if c: r += 1
    return r
