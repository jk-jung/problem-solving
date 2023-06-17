from collections import Counter
def merge_arrays(a, b):
    a, b = Counter(a), Counter(b)
    c = set(a) & set(b)
    d = {x for x in c if a[x] == b[x]}
    r = (set(a) | set(b)) - c

    return sorted(r | d)
