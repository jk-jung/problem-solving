# https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm

def bron_kerbosch(r, p, x, g):
    max_r = set()
    if len(p) == 0 and len(x) == 0:
        return r
    else:
        # Any maximal clique must include either u or one of its non-neighbors,
        # for otherwise the clique could be augmented by adding u to it.
        piv = max(p | x, key=lambda k: len(g[k]))
        for k in p - g[piv]:
            t = bron_kerbosch(r | {k}, p & g[k], x & g[k], g)
            if len(t) > len(max_r): max_r = t
            p -= {k}
            x |= {k}

    return max_r


def maximum_clique(gg):
    n = len(gg)
    g = []
    for i in range(n):
        g.append(set())
        for j in range(n):
            if gg[i][j] == 0 or i == j: continue
            g[i].add(j)

    return bron_kerbosch(set(), set(range(n)), set(), g)
