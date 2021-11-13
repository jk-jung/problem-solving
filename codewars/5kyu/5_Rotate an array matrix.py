def ro(v):
    n = len(v)
    m = len(v[0])
    r = [[0 for _ in range(n)] for _ in range(m)]
    for i in range(m):
        for j in range(n):
            r[i][j] = v[j][m-i-1]
    return r

def rotate(v, d):
    v = ro(v)
    if d == 'clockwise':
        v = ro(ro(v))
    return v