def int_diff(v, n):
    r = 0
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            if abs(v[i] - v[j]) == n:
                r += 1
    return r
