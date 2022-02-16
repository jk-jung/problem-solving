def spiralize(v):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    y, x, d = 0, 0, 0
    r = {}
    my, mx = 99999, 99999
    My, Mx = -99999, -99999
    for w in v:
        for _ in range(ord(w) - ord('a') + 1):
            y, x = y + dy[d], x + dx[d]
            r[(y, x)] = w
            my, mx = min(my, y), min(mx, x)
            My, Mx = max(My, y), max(Mx, x)
        d = (d + 1) % 4

    s = []
    for i in range(my, My + 1):
        t = ''
        for j in range(mx, Mx + 1):
            t += r.get((i, j), ' ')
        s.append(t)
    return '\n'.join(s)