def to_nato(w):
    r = []
    for x in w.upper():
        if x in NATO: r.append(NATO[x])
        elif x in ',.!?': r.append(x)
    return ' '.join(r)