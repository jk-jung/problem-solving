def count_min_rotations(a):
    r = 9999999
    for i in range(1, 7):
        t = 0
        for x in a:
            if x + i == 7:
                t += 2
            elif x != i:
                t += 1
        r = min(r, t)
    return r
