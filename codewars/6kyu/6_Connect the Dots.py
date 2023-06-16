def connect_the_dots(v):
    s = sorted(v.replace(' ', '').replace('\n', ''))
    v = [list(x) for x in v.split('\n')]

    def f(x):
        for i in range(len(v)):
            for j in range(len(v[0])):
                if v[i][j] == x: return j, i

    for a, b in zip(s, s[1:]):
        x1, y1 = f(a)
        x2, y2 = f(b)

        dx = (x2 - x1) // abs(x2 - x1) if x2 - x1 != 0 else 0
        dy = (y2 - y1) // abs(y2 - y1) if y2 - y1 != 0 else 0

        while x1 != x2 or y1 != y2:
            if v[y1][x1] in (a, b, ' '):
                v[y1][x1] = '*'
            x1 += dx
            y1 += dy
    v[y2][x2] = '*'
    return '\n'.join(''.join(x) for x in v)
