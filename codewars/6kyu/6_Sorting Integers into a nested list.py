from itertools import groupby
def group_ints(v, key=0):
    r = groupby(v, lambda x: x < key)
    return [list(x[1]) for x in r]