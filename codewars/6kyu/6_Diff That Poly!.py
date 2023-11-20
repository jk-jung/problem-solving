def diff(v):
    return [(len(v) - i - 1) * x for i, x in enumerate(v)][:-1]
