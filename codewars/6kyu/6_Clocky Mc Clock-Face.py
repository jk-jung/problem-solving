def what_time_is_it(b):
    if b == 360: b = 0
    r, t = '', 99999
    for h in range(0, 12):
        for m in range(0, 60):
            a = 30 * h + .5 * m
            if a <= b:
                hh = 12 if h == 0 else h
                r = '%02d:%02d' % (hh, m)
    return r
