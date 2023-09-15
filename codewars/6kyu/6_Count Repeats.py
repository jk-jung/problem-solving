from itertools import groupby
def count_repeats(t):
    return len(t) - len(list(groupby(t)))
