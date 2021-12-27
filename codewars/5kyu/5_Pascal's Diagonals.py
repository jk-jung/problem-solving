d = [[0 for _ in range(200)] for _ in range(200)]
d[0][0] = 1
for i in range(1, 200):
    d[i][0] = 1
    for j in range(1, i+1):
        d[i][j] = d[i-1][j-1] + d[i-1][j]


def generate_diagonal(n, l):
    return [d[n + i][i] for i in range(l)]
