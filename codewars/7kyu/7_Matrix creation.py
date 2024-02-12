def get_matrix(n):
    r = [[0 for _ in range(n)] for i in range(n)]
    for i in range(n):r[i][i] = 1
    return r
