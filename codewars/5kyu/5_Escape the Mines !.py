def solve(v, s, e):
    if s == e: return []
    n, m = len(v), len(v[0])
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    di = ['down', 'right', 'up', 'left']
    for i in range(4):
        y = s['y'] + dy[i]
        x = s['x'] + dx[i]
        if x < 0 or y < 0 or y >= m or x >= n or not v[x][y]:
            continue
        v[x][y] = False
        r = solve(v, {'x': x, 'y': y}, e)
        v[x][y] = True
        if isinstance(r, list):
            return [di[i]] + r
    return None