def pivot(v, idx):
    r = {}
    ck = [1 for _ in range(len(v[0]))]
    for i, x in enumerate(v[0]):
        try: x = eval(x)
        except: ck[i] = 0

    for row in v:
        k = row[idx]
        if k not in r:
            r[k] = ['-' for _ in range(len(row))]
            r[k][idx] = k

    t = [i for i, x in enumerate(ck) if x == 1]
    for row in v:
        for i in t:
            if r[row[idx]][i] == '-': r[row[idx]][i] = 0
            r[row[idx]][i] += float(row[i])

    return sorted(r.values(), key=lambda x: x[idx])
