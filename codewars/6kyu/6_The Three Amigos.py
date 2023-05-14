def three_amigos(v):
    r = []
    for i in range(2, len(v)):
        a = v[i-2]
        b = v[i-1]
        c = v[i]
        if a % 2 == b % 2 == c % 2:
            r.append((max(a, b, c) - min(a, b, c), i, [a, b, c]))
    if not r: return []
    return min(r)[-1]
