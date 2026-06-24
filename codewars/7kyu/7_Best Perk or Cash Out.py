def pick(A, B, v):
    a = []
    b = []
    i = 0
    for k, p in v:
        if k in A:
            a.append((p, i))
        if not (k in A or k in B):
            b.append((p, i))
        i += 1
    a.sort()
    b.sort()
    if a:
        return chr(ord("A") + a[-1][1])
    if b:
        return chr(ord("A") + b[-1][1])
    return "D"
