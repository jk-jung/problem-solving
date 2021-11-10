def bowling_score(v):
    r, b1, b2 = 0, 0, 0
    i, round = 0, 0

    while i < len(v):
        round += 1
        if round == 11:
            r += v[i] * (b1 + b2)
            if i + 1 < len(v):
                r += v[i+1] * b2
            break
        x = v[i]
        r += x * (b1 + b2 + 1)
        b1, b2 = b2, 0

        if v[i] == 10:
            b2 = 1
        else:
            i += 1
            x = v[i]
            r += x * (b1 + b2 + 1)
            b1, b2 = b2, 0

            if v[i-1] + v[i] == 10:
                b1 += 1
        i += 1
    return r