def tiaosheng(v):
    r = 60
    for i, x in enumerate(v):
        s = i * 3 + x
        if s <= 60:
            r = s - i * 3 + max(0, 60 - (s + 3))
    return r
