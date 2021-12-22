import random

def get_featured_projects(v):
    random.shuffle(v)
    r, a, b = [], 0, 0
    for x in v:
        if x['nreceiving_from'] > 5:
            if a < 7:
                r.append(x)
                a += 1
        else:
            if b < 3:
                r.append(x)
                b += 1
    for x in v:
        if x not in r and len(r) < 10: r.append(x)

    return r