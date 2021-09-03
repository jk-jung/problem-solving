from collections import Counter
def subsequence_sums(arr, s):
    d = Counter([0])
    t = 0
    r = 0
    for v in arr:
        t += v
        r += d[t-s]
        d[t] += 1

    return r