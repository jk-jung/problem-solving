def sum_pairs(v, s):
    r = {}

    for i in range(len(v)):
        k = s - v[i]
        if k in r: return [k, v[i]]
        r[v[i]] = 1
    return 