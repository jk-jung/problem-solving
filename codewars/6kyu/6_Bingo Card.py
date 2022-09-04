import random


def get_bingo_card():
    r, s = [], 1
    for k in 'BINGO':
        c = random.sample(range(s, s + 15), 4 if k == 'N' else 5)
        [r.append(k + str(x)) for x in c]
        s += 15
    return r

