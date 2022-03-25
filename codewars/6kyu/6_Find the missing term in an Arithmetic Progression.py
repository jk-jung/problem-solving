from collections import Counter


def find_missing(v):
    c = Counter(v[i] - v[i - 1] for i in range(1, len(v))).most_common()[-1][0] // 2
    for i in range(1, len(v)):
        if v[i] - v[i - 1] != c:
            return v[i] - c
