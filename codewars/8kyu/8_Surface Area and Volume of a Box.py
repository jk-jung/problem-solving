def get_size(w, h, d):
    return [(w * h + h * d + w * d) * 2, w * h * d]
