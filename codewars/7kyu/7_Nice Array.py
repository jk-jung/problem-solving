def is_nice(v):
    if not v: return False
    v = sorted(set(v))
    for i in range(len(v)):
        c = 0
        if i - 1 >= 0 and v[i-1] + 1 == v[i]: c = 1
        if i + 1 < len(v) and v[i + 1] - 1 == v[i]: c = 1
        if not c:
            return False
    return True