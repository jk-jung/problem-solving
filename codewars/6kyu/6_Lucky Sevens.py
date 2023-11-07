def lucky_sevens(v):
    r = 0
    for i in range(len(v)):
        for j in range(len(v[i])):
            if v[i][j] == 7:
                t = 0
                if i > 0: t += v[i-1][j]
                if j > 0: t += v[i][j-1]
                if i < len(v) - 1: t += v[i+1][j]
                if j < len(v[i]) - 1:t += v[i][j+1]
                q = int(t ** (1/3))
                while q**3 < t: q += 1
                if q ** 3 == t: r += 1
    return r
