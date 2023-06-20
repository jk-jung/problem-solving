def visits_on_circular_road(n, v):
    r, y = 0, 1
    for x in v:
        a, b = sorted([x, y])
        r += min(b - a, a + n - b)
        y = x
    return r
