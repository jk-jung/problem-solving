def parts_sums(l):
    s = sum(l)
    r = [s]
    for x in l:
        s -= x
        r.append(s)
    return r
