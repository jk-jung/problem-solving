def merge(line):
    r = []
    for x in line:
        if x == 0: continue
        if not r or r[-1] != x: r.append(x)
        else:
            r[-1] *= 2
            r.append(0)
    return ([x for x in r if x] + [0] * len(line))[:len(line)]
