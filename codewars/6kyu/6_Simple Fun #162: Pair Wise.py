from collections import defaultdict
def pairwise(v, n):
    c = defaultdict(list)
    for i, x in enumerate(v):
        c[x].append(i)
    r = 0
    for k, v in list(c.items()):
        if k * 2 == n:
            r += sum(v[:len(v) - len(v) % 2])
        elif k * 2 < n:
            u = c[n - k]
            r += sum(sum(x) for x in zip(v, u))
    return r
