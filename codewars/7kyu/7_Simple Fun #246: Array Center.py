def array_center(v):
    x, y = min(v), sum(v) / len(v)
    return [a for a in v if abs(a - y) < x]