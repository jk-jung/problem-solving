from collections import defaultdict
def hashify(s):
    r = defaultdict(list)
    for x, y in zip(s, s[1:] + s[0]):
        r[x].append(y)
    for k, v in r.items():
        if len(v) == 1: r[k] = v[0]
    return r