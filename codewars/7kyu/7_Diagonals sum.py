def sum_diagonals(v):
    try:
        r = 0
        for i in range(len(v)):
            r += v[i][i] + v[i][len(v) - i - 1]
        return r
    except:
        return 0
