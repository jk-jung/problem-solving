def SJF(v, index):
    r = 0
    for x in sorted(set(v)):
        for i, k in enumerate(v):
            if k == x:
                r += x
                if i == index:
                    return r
