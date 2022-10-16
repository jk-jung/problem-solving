from collections import defaultdict
def find_duplicates(v):
    d = defaultdict(list)
    r = []
    for i, x in enumerate(v):
        k = (x.first_name, x.last_name, x.user_name)
        d[k].append(i)
        if len(d[k]) >= 2:
            r.append(x)
    t = sorted(sum([list(x)[1:] for x in d.values() if len(x) >= 2], []))[::-1]
    for x in t:
        v.pop(x)
    return r
