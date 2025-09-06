def distinct(s):
    return [x for i, x in enumerate(s) if s.index(x) == i]
