from collections import Counter
def micro_world(v, k):
    r = len(v)
    v = sorted(Counter(v).items())
    for i in range(1, len(v)):
        if v[i - 1][0] < v[i][0] <= v[i - 1][0] + k:
            r -= v[i - 1][1]
    return r
