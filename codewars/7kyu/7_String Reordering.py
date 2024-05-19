def sentence(v):
    v = [list(x.items())[0] for x in v]
    v = sorted([(int(x[0]), x[1]) for x in v])
    return ' '.join([x[1] for x in v])
