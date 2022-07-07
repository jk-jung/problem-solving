def first_n_smallest(v, n):
    v = sorted(sorted((x, i) for i, x in enumerate(v))[:n], key=lambda x: x[-1])
    return [x[0] for x in v]