def knight(p1, p2):
    dx = [1, 1, -1, -1, 2, 2, -2, -2]
    dy = [2,-2,  2, -2, 1,-1,  1, -1]

    s = (ord(p1[0]) - ord('a'), int(p1[1]) - 1)
    e = (ord(p2[0]) - ord('a'), int(p2[1]) - 1)

    q = [(s, 0)]
    vis = {s: 1}

    while True:
        s, dis = q.pop(0)
        if s == e: return dis

        for i in range(8):
            n = (s[0] + dx[i], s[1] + dy[i])
            if n[0] < 0 or n[1] < 0 or n[0] >= 8 or n[1] >=8 or n in vis: continue
            vis[n] = 1
            q.append((n, dis+1))