def guess_gifts(a, b):
    r = []
    for x in b:
        for y in a:
            if x['size'] == y['size'] and x['clatters'] == y['clatters'] and x['weight'] == y['weight']:
                if y['name'] in r: continue
                r.append(y['name'])
    return r