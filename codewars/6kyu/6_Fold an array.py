def fold_array(v, n):
    if n == 0: return v
    m = len(v)
    a = v[:(m + 1) // 2]
    b = v[(m + 1) // 2 :][::-1]
    for i in range(len(b)):
        a[i] += b[i]

    return fold_array(a, n - 1)