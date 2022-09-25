from collections import Counter
def create_report(names):
    c = Counter()
    def to_name(x):
        if len(x) == 1: return x[0][:6]
        if len(x) == 2: return x[0][:3] + x[1][:3]
        if len(x) == 3: return x[0][:2] + x[1][:2] + x[2][:2]
        if len(x) == 4: return x[0][:1] + x[1][:1] + x[2][:2] + x[3][:2]
    for x in names:
        if 'Labrador Duck'.upper() in x.upper(): return ['Disqualified data']
        n, k = x.replace('-', ' ').rsplit(' ', 1)
        n = n.strip().upper().split(' ')
        c[to_name(n)] += int(k)

    return list(sum(sorted(c.items()), ()))