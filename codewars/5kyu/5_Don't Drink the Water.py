def separate_liquids(v):
    if len(v) == 0: return []
    n = len(v[0])
    s = sorted(sum(v, []), key='OAWH'.index)
    return [s[i:i+n] for i in range(0, len(s), n)]