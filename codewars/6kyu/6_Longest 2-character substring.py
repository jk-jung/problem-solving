from collections import Counter
def substring(s):
    r, t = [], []
    c = Counter()
    for x in s:
        c[x] += 1
        t.append(x)
        while len(c) > 2:
            y = t.pop(0)
            c[y] -= 1
            if c[y] == 0:
                del c[y]

        if len(r) < len(t):
            r = t[:]
    return ''.join(r)
