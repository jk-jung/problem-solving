def find_min_max_product(arr, k):
    if k > len(arr): return None
    print(arr, k)
    neg = []
    pos = []
    zero = []
    for x in sorted(arr):
        if x < 0: neg.append(x)
        else: pos.append(x)
    pos = pos[::-1]
    r1 = 0 if 0 in pos else +1e100
    r2 = 0 if 0 in pos else -1e100

    if len(neg) == 0:
        tmp = 1
        for x in pos[:k]:
            tmp *= x
        r1 = min(r1, tmp)
        r2 = max(r2, tmp)

        tmp = 1
        for x in pos[::-1][:k]:
            tmp *= x
        r1 = min(r1, tmp)
        r2 = max(r2, tmp)
    if len(pos) == 0:
        tmp = 1
        for x in neg[:k]:
            tmp *= x
        r1 = min(r1, tmp)
        r2 = max(r2, tmp)
        tmp = 1
        for x in neg[::-1][:k]:
            tmp *= x
        r1 = min(r1, tmp)
        r2 = max(r2, tmp)
    for i in range(0, min(k, len(neg)) + 1):
        rest = k - i
        tmp = 1
        for x in neg[:i]:
            tmp *= x
        for x in pos[:k - i]:
            tmp *= x
        if len(pos) < rest:
            continue
        r1 = min(r1, tmp)
        r2 = max(r2, tmp)

    return r1, r2
