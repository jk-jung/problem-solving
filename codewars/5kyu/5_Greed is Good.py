from collections import Counter


def score(dice):
    c = Counter(dice)
    r = 0

    for i in [1, 6, 5, 4, 3, 2]:
        if c[i] >= 3:
            r += i * 100 * (10 if i == 1 else 1)
            c[i] -= 3
    r += c[1] * 100
    r += c[5] * 50
    return r
