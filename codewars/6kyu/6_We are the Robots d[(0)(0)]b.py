import re
def count_robots(a):
    t = r'[|};&#\[\]/><()*]{2}'
    r = {'automatik': 0, 'mechanik': 0}
    for x in a:
        x = x.lower()
        c = len(re.findall(rf'[a-z]{t}0{t}0{t}[a-z]', x))
        for k in r:
            if k in x:
                r[k] += c
    return [f"{r['automatik']} robots functioning automatik", f"{r['mechanik']} robots dancing mechanik"]