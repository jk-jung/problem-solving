def leaderboard_climb(a, b):
    i = len(a) - 1
    t = a[0] + 1
    d = [0]
    for x in a:
        if x == t:d.append(d[-1])
        else: d.append(d[-1] + 1)
        t = x
    r = []
    for x in b:
        while i >= 0 and a[i] <= x:
            i -= 1
        r.append(d[i + 1] + 1)
    return r
