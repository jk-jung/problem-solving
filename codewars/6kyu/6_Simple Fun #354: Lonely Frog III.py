def jump_to(x, z):
    q = [(x, 0)]
    ck = {x: 1}

    def p(y, d):
        if y <= z and y not in ck:
            q.append((y, d))
            ck[y] = 1

    while q:
        x, d = q.pop(0)
        if x == z: return d
        p(x + 1, d + 1)
        p(x * 2, d + 1)

