def abundance(n):
    r = []
    for i in range(12, 99999):
        if len(r) == n: break
        t = sum([j for j in range(1, i) if i % j == 0])
        if t > i:
            r.append((t - i, i))
    return [x[1] for x in sorted(r)]
