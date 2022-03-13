def wrap(h, w, l):
    h, w, l = sorted([h, w, l])
    return h * 4 + w * 2 + l * 2 + 20