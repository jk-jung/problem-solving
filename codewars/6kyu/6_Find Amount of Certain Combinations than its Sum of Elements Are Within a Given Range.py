def find_comb_noncontig(v, t, q):
    r = 0
    for i in range(1, 1 << len(v)):
        if (i * 2) & i: continue

        s = 0
        for k in range(len(v)):
            if i >> k & 1:
                s += v[k]
        r += t - q <= s <= t + q
    return r
