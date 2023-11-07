def align_right(t, w):
    r = []
    c = ''
    for x in t.split(' '):
        if len(c) + len(x) + (len(c) > 0) > w:
            print(c, len(c), w, x)
            r.append(c)
            c = x
        else: c += (' ' if len(c) > 0 else '') + x
    r.append(c)
