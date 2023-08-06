from collections import Counter


def blocks(s):
    def f(x):
        if x.isdigit(): return ord(x) + 1000
        if x.isupper(): return ord(x) + 100
        return ord(x)
    c = Counter(s)
    r = []
    while c:
        t = list(c.keys())
        for x in t:
            c[x] -= 1
            if c[x] == 0:
                del c[x]
        r.append(''.join(sorted(t, key=f)))
    return '-'.join(r)

