def do_they_agree(a, b):
    last = -1
    for x in b:
        t = a.index(x) if x in a else -1
        if t >= 0:
            if t < last:
                return False
            last = t
    return True
