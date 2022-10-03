def cost_of_carpet(w, h, ww, c):
    if min(w, h) > ww or min(w, h) == 0: return 'error'
    if w > h: w, h = h, w

    if max(h, w) < ww: r = min(h, w) * ww * c
    else: r= max(h, w) * ww * c

    return round(r, 2)
