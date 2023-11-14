def convert(n):
    r = [0, 0]
    for i, x in enumerate(str(n)[::-1]):
        if x == '1':
            if i % 4 == 0: r[0] += 1
            if i % 4 == 1: r[1] += 1
            if i % 4 == 2: r[0] -= 1
            if i % 4 == 3: r[1] -= 1

    return r
