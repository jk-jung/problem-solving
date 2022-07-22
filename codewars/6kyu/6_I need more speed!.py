def reverse(v):
    s, e = 0, len(v) - 1
    while s < e:
        v[s], v[e] = v[e], v[s]
        s += 1
        e -= 1