def two_sum(v, n):
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            if v[i] + v[j] == n: return (i, j)
