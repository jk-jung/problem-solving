def remove_smallest(v):
    if not v: return []
    v = v[:]
    v.remove(min(v))
    return v
