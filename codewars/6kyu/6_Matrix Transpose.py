def transpose(x):
    n, m = len(x), len(x[0])
    return [[x[j][i] for j in range(n)] for i in range(m)]
