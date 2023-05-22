from itertools import groupby
def repeat_adjacent(s):
    r = 0
    c = 0
    for k, v in groupby(s + '_'):
        if len(list(v)) == 1:
            if c >= 2: r += 1
            c = 0
        else:
            c += 1
    return r