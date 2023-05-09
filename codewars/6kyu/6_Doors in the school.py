def doors(n):
    d = [1 for i in range(n + 1)]
    for i in range(2, n + 1):
        for j in range(i, n + 1, i):d[j] ^= 1
    return sum(d) - 1
