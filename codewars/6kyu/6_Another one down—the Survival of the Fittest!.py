def remove_smallest(n, v):
    if n<= 0: return v
    v = sorted((x, i) for i, x in enumerate(v))[n:]
    return [x[0] for x in sorted(v, key=lambda x: x[1])]
