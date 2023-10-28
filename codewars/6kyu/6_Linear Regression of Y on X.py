def regressionLine(x, y):
    xx = sum(a*a for a in x)
    sx = sum(x)
    sy = sum(y)
    xy = sum(a*b for a, b in zip(x, y))
    t = len(x)*xx - sx*sx

    a = (xx*sy - sx*xy) / t
    b = (len(x)*xy - sx*sy) / t
    return round(a, 4), round(b, 4)
