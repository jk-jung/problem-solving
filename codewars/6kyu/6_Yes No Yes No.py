def yes_no(v, s=0):
    if len(v) <= 1: return v
    return v[s::2] + yes_no(v[s^1::2], (s + len(v)) % 2)
