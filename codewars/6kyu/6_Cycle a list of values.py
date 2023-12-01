# d = direction, v = values array, c = number to search
# return None in case of value not found
def cycle(d, v, c):
    if c not in v: return None
    return v[(v.index(c) + d + len(v)) % len(v)]