from collections import defaultdict


def sort(w, i = 0):
    t = defaultdict(list)
    for x in w:
        if len(x) <= i: t[' '].append(x)
        else: t[x[i]].append(x)

    for x in t[' ']: yield x
    for a in alphabet:
        if len(t[a]) > 0:
            for x in sort(t[a], i + 1): yield x
