def who_is_next(names, r):
    t = [(x, 1) for x in names]
    while r:
        if r <= t[0][1]: break
        r -= t[0][1]
        t.append((t[0][0], t[0][1] * 2))
        t = t[1:]

    return t[0][0]
