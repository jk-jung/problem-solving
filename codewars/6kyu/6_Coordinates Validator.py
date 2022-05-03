def is_valid_coordinates(c):
    t = c.split(',')
    if len(t) != 2: return False

    a, b = t
    if len(b) == 0: return False
    if b[0] == ' ': b = b[1:]
    if len(b) == 0: return False

    def invalid(x):
        if x[0] == '-': x = x[1:]
        if x == 0: return True
        if x.count('.') >= 2: return True
        for c in x:
            if c.isdigit(): continue
            if c == '.': continue
            return True
        return False
    if invalid(a) or invalid(b): return False
    a = float(a)
    b = float(b)

    if not (0 <= abs(a) <= 90): return False
    if not (0 <= abs(b) <= 180): return False

    return True # do your thing
