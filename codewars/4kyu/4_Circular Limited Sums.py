def circular_limited_sums(n, m):
    d1 = [[1 if x == y else 0 for x in range(m + 1)] for y in range(m + 1)]
    for i in range(1, n):
        d2 = [[0 for _ in range(m + 1)] for _ in range(m + 1)]
        for x in range(m + 1):
            for y in range(m + 1):
                for z in range(m + 1):
                    if y + z <= m:
                        d2[x][z] = (d2[x][z] + d1[x][y]) % 12345787
        d1 = d2

    r = 0
    for x in range(m + 1):
        for y in range(m + 1):
            if x + y <= m:
                r = (r + d1[x][y]) % 12345787

    return r
