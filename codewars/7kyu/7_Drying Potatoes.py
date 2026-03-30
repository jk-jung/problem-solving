def potatoes(p0, w0, p1):
    w = p0 * w0 / 100
    x = w0 - w

    return int(x / (100 - p1) * 100 + 1e-9)
