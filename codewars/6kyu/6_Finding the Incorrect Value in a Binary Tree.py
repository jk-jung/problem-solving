def find_incorrect_value(v):
    c = [True for _ in v]
    for i in range(len(v) // 2):
        t = v[i * 2 + 1] + v[i * 2 + 2]
        if v[i] != t:
            c[i] = False
    for i in range(len(v) // 2 + 1, len(v), 2):
        r = (i - 1) // 2
        rr = (r - 1) // 2
        if not c[r] and c[rr]:
            return i, v[r] - v[i - 1]
    for i in range(len(v) // 2):
        if not c[i] and c[i * 2 + 1] and c[i * 2 + 2]:
            return i, v[i * 2 + 1] + v[i * 2 + 2]
