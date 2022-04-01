def calc(a, k, x):
    r, i = 0, 0
    while i < len(a):
        if a[i] == x:
            i += 1
        else:
            i += k
            r += 1
    return r


def array_equalization(a, k):
    return min(calc(a, k, x) for x in range(1, 11))