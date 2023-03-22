def sort_time(v):
    r = [['00:00', '00:00']]
    def dif(x):
        def f(y): return int(y[0:2]) * 60 + int(y[3:])
        t = f(v[x][0]) - f(r[-1][-1])
        if t < 0: t += 100000
        return t
    while v:
        k = 0
        for i in range(len(v)):
            if dif(i) < dif(k):
                k = i
        r.append(v.pop(k))
    return r[1:]
