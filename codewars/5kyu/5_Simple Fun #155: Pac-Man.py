def pac_man(n, pm, e):
    q = [pm]
    vis = {tuple(pm)}
    xx = {x[0] for x in e} | {-1, n}
    yy = {x[1] for x in e} | {-1, n}

    r = -1
    while len(q) > 0:
        t = q.pop(0)
        r += 1

        for i in range(-1, 2):
            for j in range(-1, 2):
                if abs(i + j) != 1: continue

                x = t[0] + i
                y = t[1] + j

                if x in xx or y in yy or (x, y) in vis: continue
                vis.add((x, y))
                q.append((x, y))
    return r
        