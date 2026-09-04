from itertools import zip_longest
def vertical(w):
    return'\n'.join(' '.join(y or ' ' for y in x).rstrip() for x in zip_longest(*w))
