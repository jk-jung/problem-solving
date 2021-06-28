def match(s):
    con = {'A': 0, 'B': 0, 'X': 1, 'Y': 1}
    n = len(s)
    d = [[0 for _ in range(n)] for _ in range(n)]
    for k in range(1, n):
        for i in range(n - k):
            v = 1 if s[i] != s[i + k] and con[s[i]] == con[s[i + k]] else 0
            if k == 1:
                d[i][i + k] = v
            else:
                d[i][i + k] = v + d[i + 1][i + k - 1]
                for j in range(i, i + k):
                    d[i][i + k] = max(d[i][i + k], d[i][j] + d[j + 1][i + k])

    return d[0][n - 1]
