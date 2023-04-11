def new_year_celebrations(s, v):
    a, b = map(int, s.split(':'))
    t = (24 * 60 - a * 60 - b) % (24 * 60)
    r, last = 0, 0
    for x in v:
        if t - last >= 0 and x >= t:
            r += 1
        t += 60
        last = x
    if v:
        if t - v[-1] >= 0: r += 1
    else:
        r += 1
    return r
