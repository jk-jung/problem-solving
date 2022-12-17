def tick_toward(s, e):
    r = [(*s,)]
    s, e = list(s), list(e)
    while s != e:
        for i in range(2):
            if s[i] < e[i]: s[i] += 1
            elif s[i] > e[i]: s[i] -= 1
        r.append((*s,))
    return r