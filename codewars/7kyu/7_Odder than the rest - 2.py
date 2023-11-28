from itertools import groupby
def oddest(a):
    if -1 in a: return -1
    def f(k):
        kk = k
        r = []
        s = []
        while k:
            s.append(k % 2)
            if k % 2: k -= 1
            k = k // 2

            if k == -1: break
        for x, y in groupby(s):
            if not r and x == 0:r.append(0)
            r.append(len(list(y)) * (-1 if x == 0 else 1))
        if len(r) == 0: r.append(0)
        if len(r) % 2 == 0:r.append(1 << 30)
        return r
    return sorted(a, key=f)[-1]
