def number_of_routes(m, n):
    d = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    for i in range(n + 1):
        for j in range(m + 1):
            if i == 0 or j == 0: d[i][j] = 1
            else: d[i][j] = d[i - 1][j] + d[i][j - 1]
    return d[n][m]
