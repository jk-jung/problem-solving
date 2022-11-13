from collections import Counter

def count_squares(v):
    r, n = 0, len(v)
    for i in range(n):
        L = len(v[i])
        for j in range(i + 1, n):
            L = min(L, len(v[j]))
            t = list(zip(v[i], v[j]))
            m = j - i
            for a in range(L - m):
                b = a + m
                if Counter([v[i][a], v[i][b], v[j][a], v[j][b]])['+'] == 4:
                    ok = True
                    for y in range(i, j + 1):
                        if v[y][a] not in '+|' or v[y][b] not in '+|':
                            ok = False
                            break
                    for x in range(a, b + 1):
                        if v[i][x] not in '+-' or v[j][x] not in '+-':
                            ok = False
                            break
                    if ok:r += 1
    return r
