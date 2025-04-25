def bounce_count(h, w, v):
    return int((h * 2 / 9.81) ** .5 * v // w)