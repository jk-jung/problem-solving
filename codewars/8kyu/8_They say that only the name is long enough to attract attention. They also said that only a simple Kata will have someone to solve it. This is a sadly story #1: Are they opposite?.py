def is_opposite(a,b):
    return bool(a) and len(a) == len(b) and all(x != y and x.lower() == y.lower() for x, y in zip(a, b))