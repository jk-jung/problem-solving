def best_parking_spot(v):
    r = 0
    def f(i):
        if v[i] != 'OPEN': return 1 << 30
        t = 1 << 30
        for j, x in enumerate(v):
            if x == 'CORRAL':
                t = min(t, abs(j - i))
        return i * 2 + t * 2

    for i in range(len(v)):
        if f(r) >= f(i):
            r = i
    return r