def generate_pairs(m, n):
    r = []
    for i in range(m, n + 1):
        for j in range(i, n + 1):
            r.append((i, j))
    return r
