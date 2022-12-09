def range_parser(ss):
    r = []
    for s in ss.split(','):
        v = s.strip().replace(':', '-').split('-')
        v = list(map(int, v))
        if len(v) == 1:
            r.append(v[0])
        elif len(v) == 2:
            r += list(range(v[0], v[1] + 1))
        else:
            r += list(range(v[0], v[1] + 1, v[2]))
    return r
