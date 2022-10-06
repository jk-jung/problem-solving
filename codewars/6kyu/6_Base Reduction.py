def basereduct(x):
    if x > 1e20:return -1
    if x < 10: return x
    t = int(max(str(x))) + 1
    if t == 10: t = 11
    r = 0
    for x in str(x):
        r = r * t + int(x)
    return basereduct(r)
