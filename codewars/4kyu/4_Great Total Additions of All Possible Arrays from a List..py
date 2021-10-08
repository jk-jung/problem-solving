def gta(limit, *args): # find the base_list first
    v = []
    for i in range(100):
        for x in args:
            if len(str(x)) <= i: continue
            y = int(str(x)[i])
            if y not in v: v.append(y)
    v = v[:limit]

    r = 0
    for x in v:
        fac = 1
        for i in range(1, len(v) + 1):
            r += x * fac * i
            fac *= (len(v) - i)

    return r