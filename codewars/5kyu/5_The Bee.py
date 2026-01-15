from collections import Counter


def the_bee(n):
    d = Counter()
    d[(0, 0)] = 1
    m = n * 2 - 1
    s = 0
    e = n
    for i in range(m):
        if i >= n:
            e -= 1
        for j in range(s, e):
            if i == 0 and j == 0:
                d[(i, j)] = 1
            else:
                d[(i, j)] = d[(i, j - 1)] + d[(i - 1, j)] + d[(i - 1, j + 1)]
        if i < n - 1:
            s -= 1
    return d[(m - 1, 0)]
