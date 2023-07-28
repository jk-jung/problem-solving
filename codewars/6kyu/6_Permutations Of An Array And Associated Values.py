from itertools import permutations
def ssc_forperm(v):
    v = [sum([(i + 1) * y for i, y in enumerate(x)]) for x in set(permutations(v))]
    return [{"total perm":len(v)}, {"total ssc": sum(v)}, {"max ssc": max(v)}, {"min ssc": min(v)}]
