from math import comb
c = [comb(x + x, x) // (x + 1) for x in range(201)]
def hankel_matrix_maker(n):
    v = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            v[i][j] = c[i + j]
    return v
