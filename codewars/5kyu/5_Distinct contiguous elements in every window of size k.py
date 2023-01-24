from collections import Counter
def count_contiguous_distinct(k, v):
    ck, q, r = Counter(), [], []
    for x in v:
        q.append(x)
        ck[x] += 1
        if len(q) > k:
            y = q.pop(0)
            ck[y] -= 1
            if ck[y] == 0:
                del ck[y]
        if len(q) == k:
            r.append(len(ck))
    return r
