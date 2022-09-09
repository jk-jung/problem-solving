def list_depth(l):
    if isinstance(l, list): return 1 + max([list_depth(x) for x in l] + [0])
    return 0