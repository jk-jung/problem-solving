def scoreboard(v):
    return sorted([
        {'name': x['name'], 'score': x.get('chickenwings',0) * 5 + x.get('hamburgers',0) * 3 + x.get('hotdogs',0)* 2} for x in v
    ], key=lambda x: (-x['score'], x['name']))
    pass
