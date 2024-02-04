from collections import Counter
def rank(v):
    c = Counter(v)
    r = {}
    t = 0
    for k, y in sorted(c.items()):
        val = 0
        for _ in range(y):
            val += t
            t += 1
        r[k] = val / y

    return [r[x] for x in v]
