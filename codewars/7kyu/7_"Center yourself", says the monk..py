def center(s, w, fill=' '):
    while len(s) < w:
        s = fill + s
        if len(s) < w:
            s += fill
    return s