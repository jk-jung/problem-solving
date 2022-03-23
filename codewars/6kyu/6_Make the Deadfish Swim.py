def parse(s):
    r, v = [], 0
    for x in s:
        if x == 'i': v += 1
        if x == 'd': v -= 1
        if x == 's': v **= 2
        if x == 'o': r.append(v)
    return r
