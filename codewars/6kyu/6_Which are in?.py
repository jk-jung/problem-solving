def in_array(a, b):
    return sorted(x for x in set(a) if any(x in y for y in b))