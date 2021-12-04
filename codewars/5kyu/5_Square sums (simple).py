sq = {4, 9, 16, 25, 36, 49, 64, 81}


def square_sums_row(n):
    v = [set() for _ in range(n + 1)]
    R = False

    def go(used, r):
        nonlocal R
        if len(used) == n:
            R = r
            return

        for i in range(1, n + 1):
            if i in used: continue
            if len(r) == 0 or i in v[r[-1]]:
                go(used | {i}, r + [i])
                if R: return

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i != j and i + j in sq:
                v[i].add(j)
                v[j].add(i)

    go(set(), [])
    return R
