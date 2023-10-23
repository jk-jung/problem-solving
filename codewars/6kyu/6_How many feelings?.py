from collections import Counter
def count_feelings(s, v):
    c = Counter(s)
    r = len([x for x in v if all(c[y] >= x.count(y) for y in x)])
    return f"{r} feeling{'' if r == 1 else 's'}."
