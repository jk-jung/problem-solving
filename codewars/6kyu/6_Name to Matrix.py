from math import ceil


def matrixfy(s):
    n = ceil(len(s) ** .5)
    if not n: return "name must be at least one letter"
    s = (s + '.' * n * n)[:n * n]
    return [[s[i * n + j] for j in range(n)] for i in range(n)]