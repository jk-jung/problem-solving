def find_part_max_prod(n):
    d = [([], 0) for _ in range(n + 1)]
    d[0] = ([[1]], 1)

    for i in range(2, n + 1):
        for j in range(2, i + 1):
            t = d[i - j]
            v = t[1] * j

            if d[i][1] == v:
                for x in t[0]:
                    d[i][0].append([j, *x])
            elif d[i][1] < v:
                d[i] = ([], v)
                for x in t[0]:
                    d[i][0].append([j, *x])

    t = set(tuple(sorted(x[:-1])) for x in d[n][0])
    t = [list(reversed(x)) for x in sorted(t, key=lambda x: len(x))]
    return [*t, d[n][1]]
