def create_spiral(n):
    try:
        r = [[0 for _ in range(n)] for _ in range(n)]
    except:
        return []

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    di = 0

    x, y = 0, 0
    for i in range(n * n):
        r[y][x] = i + 1

        for k in range(4):
            nx = x + dx[di]
            ny = y + dy[di]

            if nx == n or ny == n or nx < 0 or ny < 0 or r[ny][nx] != 0:
                di = (di + 1) % 4
            else:
                break
        x = nx
        y = ny

    return r
