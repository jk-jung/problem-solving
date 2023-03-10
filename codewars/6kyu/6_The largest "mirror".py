def max_mirror(v):
    t = ',' + ','.join(map(str, v[::-1])) + ','
    r = 0
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            s = ',' + ','.join(map(str, v[i:j + 1])) + ','
            if s in t:
                r = max(r, j - i + 1)
    return r
