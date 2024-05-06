def compress(s):
    if not s: return s
    c = {}
    r = ''
    for x in s.lower().split(' '):
        if x not in c:
            c[x] = len(c)
        r += str(c[x])
    return r
