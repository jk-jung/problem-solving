def matrix_addition(a, b):
    n = len(a)
    for i in range(n):
        for j in range(n):
            a[i][j] += b[i][j]
    return a
