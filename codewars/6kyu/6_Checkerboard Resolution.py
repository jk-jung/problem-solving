def count_checkerboard(w, h, r):
    a, b = divmod(w, r * 2)
    wc = a * r + max(0, b - r)

    a, b = divmod(h, r * 2)
    hc = a * r + max(0, b - r)

    return wc * (h - hc) + (w - wc) * hc
