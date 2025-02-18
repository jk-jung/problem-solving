def unflatten(a):
    r = []
    while a:
        if a[0] < 3:
            r.append(a.pop(0))
        else:
            r.append(a[:a[0]])
            a = a[a[0]:]
    return r