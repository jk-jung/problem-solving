def parse_mana_cost(s):
    s = s.lower()
    r = {}
    t = 0
    while s and s[0].isdigit():
        t = t * 10 + int(s[0])
        s = s[1:]
    if t: r['*'] = t
    for x in "wubrg":
        if s.count(x):
            r[x] = s.count(x)
        s = s.replace(x, '')
    if s: return None
    return r
