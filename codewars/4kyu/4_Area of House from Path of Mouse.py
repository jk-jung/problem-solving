def mouse_path(s):
    di = 0
    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]
    v = [(0, 0)]

    for k in s.replace('R', ' R ').replace('L', ' L ').split(' '):
        if k == 'R': di = (di + 1) % 4
        elif k == 'L': di = (di + 3) % 4
        else: v.append((v[-1][0] + int(k) * dx[di], v[-1][1] + int(k) * dy[di]))

    n = len(v)
    if v[-1] != (0, 0) or v[-2][1] == 0: return
    def inter(a1, a2, b1, b2):
        if a1 > a2: a1, a2 = a2, a1
        if b1 > b2: b1, b2 = b2, b1
        return min(a2, b2) - max(a1, b1) >= 0

    for i in range(2, n):
        for j in range(1, i - 1):
            if i == n - 1 and j == 1: continue
            a = inter(v[i][0], v[i-1][0], v[j][0], v[j-1][0])
            b = inter(v[i][1], v[i-1][1], v[j][1], v[j-1][1])
            if a and b:  return

    r = 0
    for i in range(0, n - 1):
        r += v[i][0] * v[i+1][1]
        r -= v[i][1] * v[i+1][0]
    return abs(r) // 2