def max_land_value(a):
    n, m = len(a), len(a[0])
    
    y1, y2 = range(0, n // 2), range((n + 1) // 2, n)
    x1, x2 = range(0, m // 2), range((m + 1) // 2, m)
    
    return max(
        sum(a[i][j] for j in x1 for i in y1),
        sum(a[i][j] for j in x2 for i in y1),
        sum(a[i][j] for j in x1 for i in y2),
        sum(a[i][j] for j in x2 for i in y2)
    )
