from collections import defaultdict
def merge(*v):
    r = defaultdict(list)
    for x in v:
        for y, z in x.items():
            r[y].append(z)
    return r
