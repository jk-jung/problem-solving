def word_pattern(w):
    r = []
    ck = {}
    for x in w.lower():
        if x not in ck: ck[x] = len(ck)
        r.append(ck[x])
    return '.'.join(map(str, r))