def leaderboard_sort(v, h):
    for x in h:
        x, t = x.split(' ')
        t = int(t)
        idx = v.index(x)
        if t >= 0:
            for i in range(t):
                v[idx - i], v[idx - i - 1] = v[idx - i - 1], v[idx - i]
        else:
            for i in range(-t):
                v[idx + i], v[idx + i + 1] = v[idx + i + 1], v[idx + i]
    return v
