def make_matrix(s, n):
    s = str(s)
    r = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j: r[i].append(s[0])
            elif i + j == n - 1: r[i].append(s[0])
            elif i < n / 2 and i < j < n - i - 1:r[i].append(s[1])
            elif i > n / 2 and i > j > n - i - 1:r[i].append(s[2])
            elif j < n / 2 and j < i < n - j - 1:r[i].append(s[3])
            else: r[i].append(s[4])
    return '\n'.join(' '.join(x) for x in r)
