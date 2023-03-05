from collections import Counter
def solve(s):
    c = Counter(s)
    for k in c:
        c[k] -= 1
        if len(set([x for x in c.values() if x > 0])) <= 1:
            return True
        c[k] += 1
    return False