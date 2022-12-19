def presentation_agenda(f):
    r = []
    for x in f:
        t = sum([y['dest'] for y in f if y != x], [])
        v = [y for y in x['dest'] if y not in t]
        if v:
            r.append({**x, 'dest': v})
    return r
