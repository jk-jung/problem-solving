from collections import Counter
def bucketize(*v):
    r = [None for _ in range(len(v) + 1)]
    for k, v in sorted(Counter(v).items()):
        if r[v] is None: r[v] = []
        r[v].append(k)
    return r
