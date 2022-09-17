from itertools import zip_longest
def combine(*args):
    return sum([[y for y in x if y is not None] for x in zip_longest(*args)], [])