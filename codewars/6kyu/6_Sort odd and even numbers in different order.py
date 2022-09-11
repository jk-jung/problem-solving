def sort_array(v):
    a = sorted([x for x in v if x % 2 == 0])[::-1]
    b = sorted([x for x in v if x % 2 == 1])
    return [a.pop(0) if x % 2 == 0 else b.pop(0) for x in v]
