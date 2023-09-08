def get_reversed_color(h):
    h = h.lower()
    while len(h) < 6: h = '0' + h
    if len(h) > 6: raise Exception('Incorrect string length')
    t = '0123456789abcdef'
    if any(x not in t for x in h): raise Exception('Non-hex chars')
    return '#' + ''.join(t[15 - t.index(x)] for x in h).upper()
