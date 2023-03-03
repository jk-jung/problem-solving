def distribute(n, w):
    r = []
    s = 0
    for i in range(n):
        m = n - i
        k = (w + m - 1) // m
        w -= k
        r.append(list(range(s, s + k)))
        s += k
    return r
