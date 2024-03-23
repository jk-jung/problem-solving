def odd_ball(v):
    t = [i for i, x in enumerate(v) if x == 'odd']

    return any(x in v for x in t)
