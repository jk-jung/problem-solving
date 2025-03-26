def swap(m, a, b, *c):
    for x in c:
        m[a][x], m[b][x] = m[b][x], m[a][x]
    return m
