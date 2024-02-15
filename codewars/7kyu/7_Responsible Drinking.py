def hydrate(s):
    s = ''.join([x for x in s if x.isdigit() or x == ' ']).split(' ')
    r = sum([int(x) if x else 0 for x in s])
    if r == 1: return '1 glass of water'
    return f'{r} glasses of water'
