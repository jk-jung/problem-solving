DD = {}

def get_dd(n, m):
    if (n, m) in DD: return (True, DD[(n, m)])
    DD[(n, m)] = [0 for _ in range(n * m + 1)]
    return (False, DD[(n, m)])


def roll_dice (n, m, t):
    d = [0 for _ in range(1)]
    d[0] = 1
    mm = 0
    for n1 in range(1, n + 1):
        processed, d2 = get_dd(n1, m)
        if processed:
            d = d2
            continue

        for i in range(len(d) - 1, -1, -1):
            if d[i]:
                for k in range(1, m + 1):
                    d2[i+k] += d[i] / m
        d = d2
    tot = sum(x for i, x in enumerate(d) if i >= t)
    return tot

