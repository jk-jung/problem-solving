def mountains_of_hoiyama(w):
    r = 0
    n = 1
    v = w
    while n * 2 - 1 <= w:
        for i in range(n):r += (v - i) * 2
        r -= v
        v -= 1
        n += 1
    return r
