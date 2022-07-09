def count_inversions(v):
    r, n = 0, len(v)
    for i in range(n):
        for j in range(i + 1, n):
            r += v[i] > v[j]
    return r

