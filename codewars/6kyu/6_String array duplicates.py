from itertools import groupby

def dup(v):
    return [''.join(k for k, _ in groupby(x)) for x in v]