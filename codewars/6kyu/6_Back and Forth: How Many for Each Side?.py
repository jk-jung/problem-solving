def minimum_amount(v):
    a, b = [1<<30], [1<<30]
    t = [[1<<30, 1<< 30]]
    for i, x in enumerate(v):
        x = -x if i % 2 else x
        a.append(a[-1] - x)
        b.append(b[-1] + x)
    return (a[0] - min(a), b[0] - min(b))
