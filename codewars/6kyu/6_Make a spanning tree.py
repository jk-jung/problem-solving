def make_spanning_tree(e, t):
    if t == 'min': e=sorted(e, key=lambda x: x[1])
    if t == 'max': e=sorted(e, key=lambda x: -x[1])

    r, s = [], []
    for x in e:
        a, b = x[0]
        if a == b: continue
        ai = next((i for i, y in enumerate(s) if a in y), None)
        bi = next((i for i, y in enumerate(s) if b in y), None)
        if ai == bi and ai is not None: continue
        elif ai == None and bi == None: s.append({a, b})
        elif ai == None: s[bi].add(a)
        elif bi == None: s[ai].add(b)
        else: s[min(ai, bi)] = s[ai] | s[bi]
        r.append(x)
    return r