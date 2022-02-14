ds = {
    'tetrahedral': 4,
    'cubic': 6,
    'octahedral': 8,
    'ninesides': 9,
    'tensides': 10,
    'dodecahedral': 12,
    'icosahedral': 20,
}


def most_prob_sum(x, n):
    m = ds[x]
    tot = m * n
    d = [0 for _ in range(tot * 2)]
    d[0] = 1

    for _ in range(n):
        for i in range(tot, -1, -1):
            for k in range(1, m + 1):
                d[i + k] += d[i] / m
            d[i] = 0
    p = max(d)
    return [[i for i in range(tot) if d[i] == p], p]
