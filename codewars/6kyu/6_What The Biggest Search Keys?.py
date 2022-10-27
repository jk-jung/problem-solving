def the_biggest_search_keys(*v):
    if not v: return "''"
    m = len(max(v, key=len))
    v = sorted([x for x in v if len(x) == m])
    return ', '.join(f"'{x}'" for x in v)
