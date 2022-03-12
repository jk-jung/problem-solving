def queue_time(v, n):
    a = [0 for _ in range(n)]
    for x in v:
        a[0] += x
        a = sorted(a)
    return a[-1]
