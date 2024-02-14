def add(*args):
    r = 0
    for i, x in enumerate(args, 1):
        r += x / i
    return round(r)
