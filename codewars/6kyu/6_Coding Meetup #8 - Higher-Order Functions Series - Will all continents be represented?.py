def all_continents(v):
    s = {x['continent'] for x in v}
    return len(s) == 5