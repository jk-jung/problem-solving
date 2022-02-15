def unique_in_order(v):
    return [x for i, x in enumerate(v) if i == 0 or v[i - 1] != x]
