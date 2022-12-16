from itertools import combinations

def find_zero_sum_groups(v, n):
    r = sorted(set([tuple(sorted(x)) for x in combinations(set(v), n) if sum(x) == 0]))
    r = list(map(list, r))
    if not v: return 'No elements to combine'
    if not r: return 'No combinations'
    return r if len(r) > 1 else r[0]