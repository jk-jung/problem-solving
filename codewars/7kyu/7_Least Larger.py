def least_larger(a, i):
    r = 1 << 30
    rr = -1
    for j in range(len(a)):
        if a[j] > a[i] and r > a[j]:
            r = a[j]
            rr = j
    return rr
