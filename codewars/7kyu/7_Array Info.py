def array_info(v):
    if not v: return 'Nothing in the array!'
    t = [
        [len(v)],
        [len([x for x in v if isinstance(x, int)])],
        [len([x for x in v if isinstance(x, float)])],
        [len([x for x in v if isinstance(x, str) and x.strip()])],
        [len([x for x in v if x == ' '])],
    ]
    for i in range(len(t)):
        if t[i] == [0]:t[i] = [None]
    return t
