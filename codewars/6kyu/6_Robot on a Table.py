def robot(n, m, s):
    x, y =  0, 0
    a,b,c,d = 0,0,0,0
    for k in s:
        if k == 'L': x -= 1
        if k == 'R': x += 1
        if k == 'U': y -= 1
        if k == 'D': y += 1

        e, f = 1 - c, 1 - a

        a = min(a, x)
        b = max(b, x)

        c = min(c, y)
        d = max(d, y)

        if b - a >= m or d - c >= n:
            return e, f
    return 1 - c, 1 - a