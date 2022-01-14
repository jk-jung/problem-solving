def pack_bagpack(ss, ww, c):
    d = [1 for _ in range(c + 1)]
    for s, w in zip(ss, ww):
        for i in range(c - w, -1, -1):
            if d[i]: d[i + w] = max(d[i + w], d[i] + s)
    return d[c] - 1