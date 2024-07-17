def shift_left(a, b):
    r = len(a) + len(b)
    for i in range(min(len(a), len(b)) + 1):
        if a[-i:] == b[-i:]:
            r = min(r, len(a) - i + len(b) - i)
    return r