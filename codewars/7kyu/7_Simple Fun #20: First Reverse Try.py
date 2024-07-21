def first_reverse_try(v):
    if not v: return v
    v[0], v[-1] = v[-1], v[0]
    return v