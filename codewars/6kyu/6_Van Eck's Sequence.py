def seq(n):
    r = [0]
    while len(r) < n:
        t = 0
        for i, x in enumerate(r[:-1][::-1]):
            if x == r[-1]:
                t = i + 1
                break
        r.append(t)
    return r[-1]
