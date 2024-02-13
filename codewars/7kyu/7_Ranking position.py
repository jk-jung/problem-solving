def ranking(v):
    v.sort(key=lambda x:(-x['points'], x['name']))
    for x in v:
        x['position'] = len([y for y in v if y['points'] > x['points']]) + 1
    return v
