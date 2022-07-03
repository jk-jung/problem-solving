def find_senior(v):
    t = max(v, key=lambda x: x['age'])
    return [x for x in v if x['age'] == t['age']]