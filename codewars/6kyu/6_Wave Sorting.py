def wave_sort(a):
    n = len(a)
    a.sort()
    r = [0 for i in range(n)]

    for i in range(1, n, 2):
        r[i] = a.pop(0)
    for i in range(0, n, 2):
        r[i] = a.pop(0)
    [a.append(x) for x in r]
    return a