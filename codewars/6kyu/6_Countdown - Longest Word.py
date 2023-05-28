from collections import Counter
def longest_word(l):
    y = Counter(l)
    r = []
    for x in words:
        z = Counter(x)
        if all(y[c] >= z[c] for c in z):
            r.append(x)
    if not r: return
    m = max([len(x) for x in r])
    return [x for x in r if len(x) == m]
