def most_common(s):
    v = sorted([(-s.count(x), i, x) for i, x in enumerate(s)])
    return ''.join(x[2] for x in v)
