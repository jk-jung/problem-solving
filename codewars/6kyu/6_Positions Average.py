def pos_average(s):
    s = s.split(', ')
    n, r = len(s), 0
    for i in range(n):
        for j in range(i + 1, n):
            r += sum(1 for x, y in zip(s[i], s[j]) if x == y)
    return r / (n * (n - 1) / 2 * len(s[0])) * 100
