def is_defended(a, b):
    r1, r2 = len(a), len(b)
    for x, y in zip(a, b):
        if x == y:r1, r2 = r1 -1, r2 -1
        elif x > y: r2 -= 1
        else: r1 -= 1

    if r1 == r2: return sum(b) >= sum(a)
    return r2 > r1
