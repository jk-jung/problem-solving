def oracle(v):
    t = ["rock","paper","scissors"]
    r = []
    for i in range(3):
        a = t[(i + 1) % 3]
        b = t[(i + 2) % 3]

        if v.count(a) < v.count(b): r.append(t[i])
    return '/'.join(r) or 'tie'
