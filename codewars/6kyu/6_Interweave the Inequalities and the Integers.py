from collections import defaultdict
def interweave(e, v):
    n = len(v)
    v = sorted(v)
    degs = [0 for _ in range(n)]

    es = defaultdict(list)
    r = [0 for _ in range(n)]
    for i in range(n - 1):
        if e[i] == '>':
            degs[i] += 1
            es[i + 1].append(i)
        else:
            degs[i + 1] += 1
            es[i].append(i + 1)
    q = [i for i, x in enumerate(degs) if x == 0]
    while len(q):
        x = q.pop(0)
        r[x] = v.pop(0)
        for y in es[x]:
            degs[y] -= 1
            if degs[y] == 0:
                q.append(y)
    return r
