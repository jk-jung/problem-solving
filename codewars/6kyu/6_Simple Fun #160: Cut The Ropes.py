from collections import Counter
def cut_the_ropes(a):
    c = Counter(a)
    r = [len(a)]
    for k, v in sorted(c.items()):
        r.append(r[-1] - v)
    return r[:-1]
