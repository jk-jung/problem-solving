move = {
    '|': ((1, 0, '|+/\\'),),
    '-': ((0, 1, '-+/\\'),),
    '/': ((1, 0, '|+'), (0, 1, '-+'), (1, -1, '/X')),
    '\\': ((1, 0, '|+'), (0, 1, '-+'), (1, 1, '\\X')),
    '+': ((1, 0, '|+/\\'), (0, 1, '-+/\\')),
    'X': ((1, 1, '\\X'), (1, -1, '/X')),
    'S': ((1, 0), (0, 1), (1, 1), (1, -1)),
    '?': ((1, 0), (0, 1), (1, 1), (1, -1)),
}


def gen(y, x, t):
    r = set()
    for di in (-1, 1):
        for m in move[t]:
            dy, dx, can, *_ = m + ('|-/\\+X', '')
            can += 'S?'
            [r.add((y + dy * di, x + dx * di, s)) for s in can]
    return r


def is_valid(y1, x1, t1, y2, x2, t2):
    return (y1, x1, t1) in gen(y2, x2, t2) and (y2, x2, t2) in gen(y1, x1, t1)


def get_next(y, x, t1, t):
    r = []
    for dy in (-1, 0, 1):
        for dx in (-1, 0, 1):
            if dy == 0 and dx == 0: continue

            ny = y + dy
            nx = x + dx

            if ny < 0 or nx < 0 or ny >= len(t) or nx >= len(t[ny]) or t[ny][nx] in (' ', '.'): continue
            t2 = t[ny][nx]

            if is_valid(y, x, t1, ny, nx, t2):
                r.append((ny, nx))
    return r


def parse_track(t):
    t = [list(x) for x in t.split('\n')]
    stn = set()
    for i, v in enumerate(t):
        stn |= {(i, j) for j, x in enumerate(v) if x == 'S'}

    x = [i for i, x in enumerate(t[0]) if x != ' '][0]
    y = 0
    r = [(y, x)]
    t[y][x] = '.'
    x += 1

    while True:
        k = t[y][x]
        if k == '.': break
        r.append((y, x))

        nxt = get_next(y, x, k, t)

        if len(nxt) == 0:
            t[y][x] = '.'
            break
        elif len(nxt) == 1:
            t[y][x] = '.'
            y, x = nxt[0]
        elif len(nxt) == 2:
            t[y][x] = '.'

            for ny, nx in nxt:
                if (ny, nx) in [p[:2] for p in r[-2:]]: continue
                y, x = ny, nx
        else:
            t[y][x] = '?'

            for ny, nx in nxt:
                dy, dx = ny - y, nx - x
                by, bx = y - dy, x - dx
                if (by, bx) not in nxt:
                    y, x = ny, nx
                    break

    return r, stn


def collide(sa, sb, t):
    n = len(t)

    def pos(s):
        di = 1 if s[0][0].isupper() else -1
        return [t[(s[1] + di * i + n) % n] for i in range(len(s[0]))]

    ssa = pos(sa)
    ssb = pos(sb)

    if len(ssa) != len(set(ssa)): return True
    if len(ssb) != len(set(ssb)): return True

    return len(set(ssa) & set(ssb)) > 0


def train_crash(track, a, ap, b, bp, limit):
    t, stn = parse_track(track)

    sa = [a, ap, 0]
    sb = [b, bp, 0]
    for i in range(limit + 1):
        if collide(sa, sb, t):
            return i

        def move(s):
            if s[2] > 0:
                s[2] -= 1
            else:
                s[1] += -1 if s[0][0].isupper() else 1
                s[1] = (s[1] + len(t)) % len(t)
                if t[s[1]] in stn and 'X' not in s[0]:
                    s[2] = len(s[0]) - 1

        move(sa)
        move(sb)

    return -1
