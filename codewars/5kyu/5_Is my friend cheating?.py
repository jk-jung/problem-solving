def remov_nb(n):
    r = []
    s = (n + 1) * n // 2
    for i in range(1, n + 1):
        j = (s - i) // (i + 1)
        if i * j == s - i - j and j <= n:
            r.append((i, j))

    return sorted(r)
