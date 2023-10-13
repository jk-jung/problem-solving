def update_inventory(a, b):
    a = list(map(list, a))
    b = list(map(list, b))
    for x in b:
        ok = False
        for y in a:
            if x[1] == y[1]:
                y[0] += x[0]
                ok = True
        if not ok: a.append(x)
    return sorted([tuple(x) for x in a], key=lambda x: x[1])
