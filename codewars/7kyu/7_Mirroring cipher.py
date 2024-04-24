def mirror(c, d=None):
    if d is None:
        d = 'abcdefghijklmnopqrstuvwxyz'
    c = c.lower()
    r = ''
    for x in c:
        if x in d:
            r += d[len(d) - d.find(x) - 1]
        else:
            r += x
    return r
