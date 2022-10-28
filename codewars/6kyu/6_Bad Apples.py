def bad_apples(apples):
    r, t = [], []
    for x in apples:
        if max(x) == 0: continue
        if min(x) == 0:
            if t:
                t[0].append(max(x))
                t = []
            else:
                r.append([max(x)])
                t.append(r[-1])
        else:
            r.append(x)
    return [x for x in r if len(x) == 2]
