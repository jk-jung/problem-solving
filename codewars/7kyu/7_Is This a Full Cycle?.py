def full_cycle(v):
    i = 0
    c = 0
    while v[i] != -1:
        j = v[i]
        v[i] = -1
        i = j
        c += 1
    return c == len(v)
