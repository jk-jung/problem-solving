def trump_detector(s):
    y, l = '', -2
    r, c = 0, 0
    for i, x in enumerate(s.lower()):
        if x in 'aeiou' and y == x: r += 1
        if x in 'aeiou' and y != x: c += 1
        y = x
    return round(r / c, 2) if c else 0
