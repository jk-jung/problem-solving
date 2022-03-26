def find_wrong_way_cow(v):
    n, m = len(v), len(v[0])
    dx = [1 ,0, -1, 0]
    dy = [0, 1, 0, -1]
    dc = [[], [], [], []]
    for i in range(n):
        for j in range(m):
            if v[i][j] == 'c':
                for k in range(4):
                    y = i + dy[k]
                    x = j + dx[k]
                    if y < 0 or x < 0 or y == n or x == m or v[y][x] != 'o': continue
                    y = y + dy[k]
                    x = x + dx[k]
                    if y < 0 or x < 0 or y == n or x == m or v[y][x] != 'w': continue
                    dc[k].append([j, i])

    return [x for x in dc if len(x) == 1][0][0]