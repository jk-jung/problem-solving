def Zeckendorf_rep(n):
    if n < 0: return None
    f = [0, 1]
    for i in range(200):f.append(f[-1] + f[-2])
    f = f[::-1]
    r = []
    flag = False
    for x in f:
        if flag:
            flag = False
            continue
        if x <= n:
            r.append(x)
            n -= x
            flag = True
    return r[:-1]
