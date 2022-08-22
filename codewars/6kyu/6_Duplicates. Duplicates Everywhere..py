def remove_duplicate_ids(obj):
    ck = {}
    for k, v in obj.items():
        k = int(k)
        for x in v:
            if x not in ck or ck[x] < k:
                ck[x] = k

    return {
        k: [x for i, x in enumerate(v) if ck[x] == int(k) and v.index(x) == i]
        for k, v in obj.items()
    }