def x(n):
    r = [[1 if i == j or i + j == n - 1 else 0 for j in range(n)] for i in range(n)]
    return r
