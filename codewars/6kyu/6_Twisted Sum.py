def compute_sum(n):
    r = 0
    for x in range(1, n + 1):
        for y in str(x):
            r += int(y)
    return r
