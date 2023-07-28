def longest_bouncy_list(v):
    r = []
    for i in range(len(v)):
        t = []
        for x in v[i:]:
            if len(t) == 0:t.append(x)
            elif len(t) == 1:
                if t[-1] != x:t.append(x)
                else: break
            else:
                if t[-2] < t[-1] > x: t.append(x)
                elif t[-2] > t[-1] < x: t.append(x)
                else: break
        if len(r) < len(t): r = t
    return r
