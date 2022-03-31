def black_and_white(h, w, v):
    r = [[]]

    for i in range(len(v)):
        x = v[i]
        while x:
            if i % 2 != len(r[-1]) % 2:
                r[-1].append(0)
            k = x
            if sum(r[-1]) + x > w:
                k = w - sum(r[-1])
            r[-1].append(k)
            x -= k
            if sum(r[-1]) == w:
                if len(r[-1]) % 2:
                    r[-1].append(0)
                r.append([])

    return r[:-1]
