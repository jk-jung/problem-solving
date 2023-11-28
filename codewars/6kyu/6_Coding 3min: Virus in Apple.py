import copy
def infect_apple(a, N):
    n, m = len(a), len(a[0])
    v = []
    for i in range(n):
        for j in range(m):
            if a[i][j] == 'V':
                v.append((i, j))

    r = copy.deepcopy(a)
    for i in range(n):
        for j in range(m):
            for y, x in v:
                if abs(y - i) + abs(x - j) <= N:
                    r[i][j] = 'V'
    return r
