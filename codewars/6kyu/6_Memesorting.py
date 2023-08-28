def memesorting(s):
    a = ['bug', 'boom', 'edits']
    b = ['Roma', 'Maxim', 'Danik']
    r = 'Vlad'
    w= 1 << 30
    for x, z in zip(a, b):
        o = 0
        ok = True
        t = []
        for y in x:
            i = s.lower().find(y, o)
            if i == -1:
                ok = False
                break
            o = i + 1
            t.append(i)

        if ok and t[-1] < w:
            w = t[-1]
            r = z
    return r
