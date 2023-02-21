def hamming_rotate(a, b):
    r = 1 << 30
    idx = -1
    for i in range(len(a)):
        t = sum(x != y for x, y in zip(a, b))
        if r > t:
            r = t
            idx = i
        a = a[-1] + a[:-1]

    return idx
