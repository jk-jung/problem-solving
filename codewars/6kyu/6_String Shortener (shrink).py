def shorten(s, l, g='...'):
    if len(s) < l: return s
    if 2 + len(g) > l:
        return s[:l]

    a, b, st, s = '', '', 1, list(s)
    while len(a + g + b) < l:
        if st: b = s.pop(-1) + b
        else: a += s.pop(0)
        st ^= 1

    return a + g + b
