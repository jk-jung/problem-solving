def sqInRect(w, h):
    if w == h: return None
    r = []
    while w * h:
        if h > w: w, h = h, w
        r.append(h)
        w -= h
    return r