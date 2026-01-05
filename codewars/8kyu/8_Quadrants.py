def quadrant(x, y):
    if x > 0:
        return 1 if y > 0 else 4
    return 2 if y > 0 else 3
