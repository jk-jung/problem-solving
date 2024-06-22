def elimination(v):
    return next((x for x in v if v.count(x) >= 2), None)
