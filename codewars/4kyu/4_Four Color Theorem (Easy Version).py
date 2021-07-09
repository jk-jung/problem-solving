from collections import defaultdict

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def bfs(v, y, x, edges):
    n = len(v)
    m = len(v[0])

    q = [(y, x)]
    vis = set()
    vis.add((y, x))

    while len(q) > 0:
        (y, x) = q.pop(0)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or nx < 0 or ny == n or nx == m: continue
            if v[y][x] != v[ny][nx]:
                edges[v[y][x]].add(v[ny][nx])
            if (ny, nx) not in vis:
                vis.add((ny, nx))
                q.append((ny, nx))


def check(edges, color):
    for x, v in edges.items():
        for y in v:
            if color[x] == color[y]: return False
    return True


def dfs(x, c, edges, color):
    if x == len(edges):
        return check(edges, color)
    for i in range(c):
        color[list(edges.keys())[x]] = i
        if dfs(x + 1, c, edges, color): return True
    return False


def can_color(c, edges):
    return dfs(0, c, edges, {})


def color(testmap):
    edges = defaultdict(set)
    bfs(testmap.strip().split('\n'), 0, 0, edges)

    if len(edges) <= 1: return 1
    if can_color(2, edges): return 2
    if can_color(3, edges): return 3
    return 4
