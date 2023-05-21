def line_up(s):
    r, t = 0, 0
    for x in s:
        if x in "LR": t ^= 1
        if t == 0: r += 1
    return r
