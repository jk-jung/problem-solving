def rotate_cw(v):
    if not v: return []
    n, m = len(v), len(v[0])
    if n == 0 or m == 0: return []

    r = []
    for i in range(n + m - 1):
        y = i
        r.append([])
        for j in range(n + m):
            try:
                r[-1].append(v[y][j])
            except:
                pass
            y -= 1
            if y < 0:
                break

    return r

def rotate_ccw(v):
    t = rotate_cw(v[::-1])
    return t[::-1]