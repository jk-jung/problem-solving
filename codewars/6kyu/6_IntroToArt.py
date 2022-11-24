def get_w(h):
    if h < 2: return []
    m = h * 2 - 3
    r = ['*' + ' ' * m + '*' + ' ' * m + '*']
    for i in range(1, h - 1):
        m -= 2
        t = ' ' * i + '*' + ' ' * m + '*' + ' ' * i
        r.append(t + t[1:])
    r.append(('*' + ' ' * (h * 2 - 3) + '*').center(len(r[0])))
    return r
