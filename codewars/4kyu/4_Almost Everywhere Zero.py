
def go(idx, same, s, k, d):
    if k < 0: return 0
    if idx == len(s): return 1 if k == 0 else 0

    kk = (idx, same, k)
    if kk in d: return d[kk]

    r = 0
    v = int(s[idx])
    for i in range(10):
        if same == 1 and i > v: break
        if same == 1 and v == i: nxt = 1
        else: nxt = 0

        nxt_k = k if i == 0 else k - 1
        r += go(idx + 1, nxt, s, nxt_k, d)

    d[kk] = r
    return r

def almost_everywhere_zero(n, k):
    return go(0, 1, str(n), k, {})
