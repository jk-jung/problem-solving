from itertools import zip_longest

def interleave(*args):
    return sum([list(x) for x in zip_longest(*args)], [])
