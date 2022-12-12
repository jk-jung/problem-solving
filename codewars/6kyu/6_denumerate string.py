def denumerate(v):
    if not isinstance(v, list): return False
    for x in v:
        if not isinstance(x, tuple) or len(x) != 2: return False
        if not isinstance(x[0], int): return False
        if not isinstance(x[1], str) or len(x[1]) != 1 or not x[1].isalnum(): return False
    r = ''
    for i, x in enumerate(sorted(v)):
        if i != x[0]: return False
        r += x[1]
    return r
