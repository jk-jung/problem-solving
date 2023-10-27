from collections import Counter
def consecutive_nums(v, m):
    if len(v) % m: return False
    c = Counter(v)
    for x in sorted(c.keys()):
        t = c[x]
        for i in range(x, x + m):
            c[i] -= t
            if c[i] < 0:
                return False
    return all(x == 0 for x in c.values())
