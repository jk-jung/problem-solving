def circularly_sorted(v):
    t = sorted(v)
    for i in range(len(v)):
        v = v[1:] + v[:1]
        if v == t:
            return True
    return False
