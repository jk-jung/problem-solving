from collections import Counter
def missing_values(seq):
    r = 1
    for k, v in Counter(seq).items():
        if v == 1: r *= k * k
        elif v == 2: r *= k
    return r
