def min_value(a, n):
    return [min(a[i : i + n]) for i in range(len(a) - n + 1)]
