def calc_rot_time(box):
    r = 0
    n, m = len(box), len(box[0])
    while True:
        ok = True
        nxt = [x[:] for x in box]
        for i in range(n):
            for j in range(m):
                if box[i][j] != 1: continue

                ck = False
                for k in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                    y = i + k[0]
                    x = j + k[1]
                    if x < 0 or y < 0 or x >= m or y >= n or box[y][x] != 2: continue
                    ck = True
                if ck:
                    nxt[i][j] = 2
                    ok = False
        if ok: break
        box = nxt
        r += 1
    for i in range(n):
        for j in range(m):
            if box[i][j] == 1: return -1
    return r
