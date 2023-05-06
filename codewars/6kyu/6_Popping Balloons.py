from collections import Counter
def freq_stack(n, v):
    r = []
    while len(r) < n:
        c = Counter(v)
        m = c.most_common(1)[0][1]
        for i in range(len(v) - 1, -1, -1):
            if c[v[i]] == m:
                r.append(v[i])
                v.pop(i)
                break
    return r
