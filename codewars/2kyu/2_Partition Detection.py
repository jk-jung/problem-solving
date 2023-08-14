from collections import namedtuple
Point = namedtuple("Point", "x y")
from collections import defaultdict


def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if abs(val) < 1e-9:
        return 0  # Collinear
    return 1 if val > 0 else 2  # Clockwise or Counterclockwise

def onSegment(p, q, r):
    return (q[0] <= max(p[0], r[0]) and q[0] >= min(p[0], r[0]) and
            q[1] <= max(p[1], r[1]) and q[1] >= min(p[1], r[1]))

def getIntersectionPoint(seg1, seg2):
    try:
        (x1, y1), (x2, y2) = seg1
        (x3, y3), (x4, y4) = seg2

        t1 = ((x3 - x1) * (y4 - y3) - (y3 - y1) * (x4 - x3)) / ((x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3))

        x = x1 + t1 * (x2 - x1)
        y = y1 + t1 * (y2 - y1)
    except:
        return None

    return Point(x, y)

def is_inter(seg1, seg2):
    p1, q1 = seg1
    p2, q2 = seg2

    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    p = getIntersectionPoint(seg1, seg2)
    if o1 != o2 and o3 != o4:
        return True, p

    if o1 + o2 + o3 + o4 == 0:
        if onSegment(p1, p2, q1): return 2
        if onSegment(p1, q2, q1): return 2
        if onSegment(p2, p1, q2): return 2
        if onSegment(p2, q1, q2): return 2

    if o1 == 0 and onSegment(p1, p2, q1):
        return True, p
    if o2 == 0 and onSegment(p1, q2, q1):
        return True, p
    if o3 == 0 and onSegment(p2, p1, q2):
        return True, p
    if o4 == 0 and onSegment(p2, q1, q2):
        return True, p

    return False, None

def merge(seg1, seg2):
    p1, q1 = seg1
    p2, q2 = seg2
    return [min(p1, q1, p2, q2), max(p1, q1, p2, q2)]


def cut(seg, w, h):
    p, q = seg
    if p.x == q.x:
        t = sorted([0, p.y, q.y, h])
        return Point(p.x, t[1]), Point(q.x, t[2])
    if p.y == q.y:
        t = sorted([0, p.x, q.x, w])
        return Point(t[1], p.y), Point(t[2], q.y)

    r = [p, q]
    for s2 in [
        [Point(0, 0), Point(w, 0)],
        [Point(w, 0), Point(w, h)],
        [Point(w, h), Point(0, h)],
        [Point(0, h), Point(0, 0)],
    ]:
        inter, t = is_inter(s2, seg)
        if inter:
            r.append(t)

    r = sorted(r)
    if len(r) > 2:
        tt = []
        for x in r:
            if any(abs(y.x - x.x) < 1e-9 and abs(y.y - x.y) < 1e-9 for y in tt): continue
            tt.append(x)
        r = tt
    return [x for x in r if 0 <= x.x <= w and 0 <= x.y <= h]


def has_partitions(w, h, v):
    v = sorted([sorted(cut(sorted(x), w, h)) for x in v])
    v = [x for x in v if len(x) == 2 and not (x[0].x == x[1].x and x[0].y == x[1].y)]
    v = [
            [Point(0, 0), Point(w, 0)],
            [Point(w, 0), Point(w, h)],
            [Point(w, h), Point(0, h)],
            [Point(0, h), Point(0, 0)],
        ] + v

    ex = set()
    while True:
        ok = True
        for i, x in enumerate(v):
            for j, y in enumerate(v):
                if (i in ex) or (j in ex): continue
                if i < j and is_inter(x, y) == 2:
                    v[i] = merge(x, y)
                    ex.add(j)
                    ok = False
        if ok: break

    v = [x if i > 3 else x for i, x in enumerate(v) if i not in ex]


    e = defaultdict(list)
    for i, x in enumerate(v):
        for j, y in enumerate(v):
            if i >= j: continue
            inter, p = is_inter(x, y)
            if inter:
                e[i].append((j, p))
                e[j].append((i, p))

    ck = set()
    def dfs(x, cur, y = -1, p=(None, None)):
        if x in cur:
            return True if sorted(cur) != [0, 1, 2, 3] else False
        if x in ck: return False
        ck.add(x)
        for z, pp in e[x]:
            if y != z and p != pp and dfs(z, cur + [x], x, pp):
                return True
        return False

    for i in range(len(v)):
        if dfs(i, []): return True
    return False
