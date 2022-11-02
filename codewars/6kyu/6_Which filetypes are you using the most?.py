from collections import Counter
def solve(v):
    c = Counter(x.split('.')[-1] for x in v)
    c = sorted(c.items(), key=lambda x: (-x[1], x[0]))
    return ['.' + x[0] for x in c if x[1] == c[0][1]]
