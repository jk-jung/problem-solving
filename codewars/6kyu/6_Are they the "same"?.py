def comp(a, b):
    if a is None or b is None: return False
    return sorted([x * x for x in a]) == sorted(b)
