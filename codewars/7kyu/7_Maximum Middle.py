def maximum_median(v, n):
    return max(v[i] for i in range(n // 2, len(v) - n // 2))
