from collections import Counter

def generate_report(v):
    v = list(v)
    v.sort(key=lambda x: (x[1], x[0]))
    r = {}
    for x in v:
        if x[1] not in r: r[x[1]] = Counter()
        r[x[1]][x[0]] += x[2]


    s = ''
    gtot = 0
    for k, v in r.items():
        s += f'\nGroup: {k}\n'
        tot = 0
        for x, cnt in v.items():
            s += f'    Product: {x} Value: {cnt:6d}\n'
            tot += cnt
            gtot += cnt
        s += f'    Group total:                {tot:6d}\n'
    s += f'\nTotal:                          {gtot:6d}'
    return s.strip()
