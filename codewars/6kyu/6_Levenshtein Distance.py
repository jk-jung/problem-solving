def levenshtein(a, b):
    r = {(-1, -1): 0}
    for i in range(max(len(a), len(b))):
        r[(-1, i)] = r[(i, -1)] = i + 1
    for i in range(len(a)):
        for j in range(len(b)):
            r[(i, j)] = min(
                r.get((i - 1, j), 1 << 30) + 1,
                r.get((i, j - 1), 1 << 30) + 1,
                r.get((i - 1, j - 1), 1 << 30) + (0 if a[i] == b[j] else 1)
            )
    return r[(len(a) - 1, len(b) - 1)]
