def arrange(s):
    v = s.lower().split(' ')
    for i in range(1, len(v)):
        x, y = i, i - 1
        if i % 2: x, y = y, x
        if len(v[x]) > len(v[y]):
            v[x], v[y] = v[y], v[x]
    for i in range(1, len(v), 2):
        v[i] = v[i].upper()
    return ' '.join(v)
