def find_dups_miss(v):
    a, b = min(v), max(v)

    t = [0 for _ in range(b + 1)]
    for x in v:
        t[x] += 1
    r1, r2 = 0, []
    for i in range(a, b + 1):
        if t[i] == 0: r1 = i
        if t[i] >= 2: r2.append(i)

    return [r1, r2]
