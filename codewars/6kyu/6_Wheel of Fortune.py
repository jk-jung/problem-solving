def winner(c):
    if len(c) != 3: return False
    r = ''
    t = -1
    for x in c:
        if 'name' not in x: return False
        if 'scores' not in x: return False
        s = sum(x['scores'])
        if not( 1 <= len(x['scores']) <= 2): return False
        if any(y not in range(5, 101, 5) for y in x['scores']): return False

        if s <= 100 and s > t:
            t = s
            r = x['name']
    return r if r else False
