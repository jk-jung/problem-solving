from collections import Counter

def find_rarest_pepe(v):
    r = Counter(v)
    t = [x for x in r.items() if x[1] == list(r.most_common())[-1][1] and x[1] < 5]
    if len(t) == 1: return t[0][0]
    if t: return sorted([x[0] for x in t])
    return 'No rare pepes!'
