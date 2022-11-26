def sort_by_guide(v, g):
    a = sorted([(y, x) for x, y in zip(v, g) if y != -1])
    return [x if y == -1 else a.pop(0)[1] for x, y in zip(v, g)]
