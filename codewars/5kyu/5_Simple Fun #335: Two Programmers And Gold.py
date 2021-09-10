def distribution_of(v):
    n = len(v)
    d = [[-1 for _ in range(n)] for _ in range(n)]

    def go(s, e, t):
        if s > e: return 0

        r = d[s][e]
        if r != -1: return r

        if t == 0:
            r = max(
                go(s + 1, e, t ^ 1) + v[s],
                go(s, e - 1, t ^ 1) + v[e]
            )
        else:
            r = min(
                go(s + 1, e, t ^ 1),
                go(s, e - 1, t ^ 1)
            )

        d[s][e] = r
        return r

    r = go(0, n - 1, 0)
    return (r, sum(v) - r)
