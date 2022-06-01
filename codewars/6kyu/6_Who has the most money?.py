def most_money(v):
    def m(x):
        return x.fives * 5 + x.tens * 10 + x.twenties * 20
    if len(v) > 1 and all(m(x) == m(v[0]) for x in v):
        return 'all'
    return sorted(v, key=m)[-1].name
