def order(k, q):
    for i, x in enumerate(q):
        x['d'] = x['from'] < x['to']
        x['i'] = i
    v = []
    r = []

    def move(s, e):
        nonlocal k
        cap = 5 - len(v)
        if cap == 0:
            k = e
            return
        d = s < e
        m = min(s, e)
        mm = max(s, e)

        candi = []
        for i in range(len(q)):
            if q[i]['d'] == d:
                if d and m <= q[i]['from'] < mm:
                    candi.append((abs(k - q[i]['from']), i, q[i]['from']))
                elif not d and m < q[i]['from'] <= mm:
                    candi.append((abs(k - q[i]['from']), i, q[i]['from']))
        candi.sort()
        if candi:
            pos, idx, real = candi[0]
            r.append(real)
            v.append(q.pop(idx))
            k = real
        else:
            k = e

    while True:
        if not q and not v:break
        if not v:
            if q[0]['from'] == k:
                r.append(q[0]['from'])
                v.append(q.pop(0))
            else:
                move(k, q[0]['from'])
        else:
            t = [x for x in v if x['to'] == k]
            if t:
                r.append(t[0]['to'])
                v = [x for x in v if x['to'] != k]
            else:
                e = min((abs(k - x['to']), x['to']) for x in v)[1]
                move(k, e)
    rr = ['a']
    for x in r:
        if rr[-1] != x:rr.append(x)
    return rr[1:]
