def spidey_swings(v):
    ww = sum(x[1] for x in v)

    vh = [[] for _ in range(ww+1)]
    d = [1<<30 for _ in range(ww+1)]
    fr = [-1 for _ in range(ww+1)]
    fr2 = [-1 for _ in range(ww+1)]
    s = 0
    for h, w in v:
        for i in range(s, s + w + 1):
            vh[i].append(h)
        s += w
    d[0] = 0

    for i in range(ww):
        if d[i] == (1<<30): continue
        candi = []
        for k in range(1, 215):
            if i + k > ww: continue
            for h in vh[i+k]:
                web = ((h-50) ** 2 + k ** 2) ** .5
                if h - web < 20: continue
                nxt = min(ww, i + k + k)
                dis = nxt - i
                candi.append((nxt == ww, dis / web ,nxt, i + k, h, int(h - web)))


        candi.sort()
        nxt= candi[-1][2]
        d[nxt] = 0
        fr[nxt] = i
        fr2[nxt] = candi[-1][3]

    r = []
    while fr[ww] != -1:
        r = [fr2[ww]] + r
        ww = fr[ww]

    return r