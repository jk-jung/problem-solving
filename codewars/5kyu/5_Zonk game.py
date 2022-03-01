from collections import Counter


def get_score(dice):
    c = Counter(dice)
    v = list(c.values())
    if len(v) == 6: return 1000
    if v == [2, 2, 2]: return 750

    r = 0
    for k, x in c.items():
        if x < 3:
            r += (100 * x if k == 1 else 0)
            r += (50 * x if k == 5 else 0)
        else:
            r += (k * 100) * (x - 2) * (10 if k == 1 else 1)

    return r or "Zonk"
