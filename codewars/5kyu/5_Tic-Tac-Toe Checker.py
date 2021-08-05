def is_solved(v):
    for i in range(3):
        a1, a2, a3, a4 = 1, 1, 1, 1
        b1, b2, b3, b4 = 2, 2, 2, 2

        for j in range(3):
            a1 &= v[i][j]
            a2 &= v[j][i]
            a3 &= v[j][j]
            a4 &= v[j][2 - j]
            b1 &= v[i][j]
            b2 &= v[j][i]
            b3 &= v[j][j]
            b4 &= v[j][2 - j]
        if a1 == 1 or a2 == 1 or a3 == 1 or a4 == 1: return 1
        if b1 == 2 or b2 == 2 or b3 == 2 or b4 == 2: return 2

    t = ''.join(''.join(str(y) for y in x) for x in v)
    if t.count('0') == 0: return 0
    return -1
