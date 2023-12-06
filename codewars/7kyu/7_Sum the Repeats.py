from collections import Counter
def repeat_sum(l):
    r = Counter()
    for y in l:
        for x in set(y):r[x]+=1
    return sum([k for k, v in r.items() if v >= 2])
