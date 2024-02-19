def day_plan(a, b, c):
    a *= 60
    if b * c > a: return 'You\'re not sleeping tonight!'
    if not b: return []
    r = [c]
    a -= b * c
    for i in range(1, b):
        r.append(round(a / (b - 1)))
        r.append(c)
    return r
