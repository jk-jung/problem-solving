from itertools import accumulate
def prefix_sums_to_suffix_sums(v):
    t = [v[0]] + [y - x for x, y in zip(v, v[1:])]
    return list(accumulate(t[::-1]))[::-1]
