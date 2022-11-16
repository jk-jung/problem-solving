from itertools import combinations

def pair_items(a, b):
    ck = False
    if len(a) > len(b):
        a, b = b, a
        ck = True

    r = []
    for t in combinations(b, len(a)):
        if ck:
            r.append(list(zip(t, a)))
        else:
            r.append(list(zip(a, t)))
    return r
