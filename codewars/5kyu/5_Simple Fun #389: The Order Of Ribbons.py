from collections import Counter


def the_order_of(v):
    r = ('', 0)
    for y, x in ((12, 1), (1, 12)):
        for i in range(11):
            s = list(Counter(v[y * i + x * j] for j in range(11) if v[y * i + x * j] != '.').items())
            if len(s) == 1 and s[0][1] > r[1]: r = s[0]
    return '' if r[0] == '' else the_order_of(v.replace(r[0], '.')) + r[0]