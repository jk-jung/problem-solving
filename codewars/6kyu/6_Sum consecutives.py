from itertools import groupby

def sum_consecutives(s):
    return [sum(x[1]) for x in groupby(s)]
