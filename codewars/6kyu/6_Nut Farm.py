def shake_tree(v):
    r = [1 if x == 'o' else 0 for x in v[0]]
    for i in range(1, len(v)):

        t = [0 for _ in range(len(v[i]))]
        for j, x in enumerate(v[i]):
            if x == '/': t[j - 1] += r[j]
            elif x == '\\': t[j + 1] += r[j]
            elif x != '_': t[j] += r[j]
        r = t
    return r
