from collections import Counter
def remember(s):
    c = Counter()
    r = []
    for x in s:
        if c[x] == 1:r.append(x)
        c[x] += 1
    return r