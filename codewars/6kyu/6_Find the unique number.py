from collections import Counter


def find_uniq(v):
    for k, v in Counter(v).items():
        if v == 1: return k
