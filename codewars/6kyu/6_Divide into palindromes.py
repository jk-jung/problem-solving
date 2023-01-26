from collections import Counter

def lowest(s):
    c = Counter(s)
    k = len([x for x in c if c[x] % 2 == 1])
    t = sum([c[x] // 2 for x in c])
    return 1 + (t // k) * 2 if k else len(s)
