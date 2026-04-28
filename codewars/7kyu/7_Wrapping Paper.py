def wrapping_paper(x):
    r = 0
    for a, b, c in x:
        x = a * b
        y = a * c
        z = b * c
        r += (x + y + z) * 2 + min(x, y, z)
    return r
