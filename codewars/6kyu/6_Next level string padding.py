def super_pad(s, w, fill=" "):
    if w == 0: return ''
    if not fill: return s[:w]
    if fill[0] == '<':
        fill = fill[1:]
        if not fill: fill = ' '
    if fill[0] == '^':
        if len(s) >= w: return s[:w]
        i = 0
        fill = fill[1:]
        if not fill:
            return s[:w]
        a = ''
        while len(s) + len(a) < w:
            if len(s) + len(a) < w: a += fill[i]
            if len(s) + len(a) < w: s = s + fill[i]
            i = (i + 1) % len(fill)
        return a + s
    elif fill[0] == '>':
        return (s + fill[1:] * w)[:w]
    else:
        if len(s) >= w: return s[-w:]
        return (fill * w)[:w - len(s)] + s