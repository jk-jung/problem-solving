def sort_sequence(s):
    v = []
    t = []
    for x in s:
        if x == 0:
            v.append(t)
            t = []
        else: t.append(x)

    v = [sorted(x) for x in v]
    for x in v:x.append(0)
    return sum([x[1] for x in sorted(enumerate(v), key=lambda x: (sum(x[1]), x[0]))], [])
