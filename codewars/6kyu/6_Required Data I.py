from collections import Counter
def count_sel(v):
    c = Counter(v)
    m = c.most_common(1)[0][1]
    return [
        len(v),
        len(c),
        len([x for x in c.values() if x == 1]),
        [
            sorted([x for x, y in c.items() if y == m]),
            m
        ]
    ]
