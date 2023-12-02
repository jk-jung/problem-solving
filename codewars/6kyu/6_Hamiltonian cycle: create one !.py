def find_cycle(a,b) : # grid a x b
    if a == 1 or b == 1:return None
    if a % 2 and b % 2: return None
    flag = False
    if a % 2: a, b, flag = b, a, True

    r = [(0, 0)]
    for i in range(a):
        g = list(range(1, b))
        if i % 2: g = g[::-1]
        [r.append((i, j)) for j in g]
    for i in range(a - 1, -1, -1):
        r.append((i, 0))

    if flag:
        r = [(y, x) for x, y in r]
    return r
