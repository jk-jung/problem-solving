def shorter_reverse_longer(a, b):
    if len(a) < len(b): a, b = b, a
    return b + a[::-1] + b
