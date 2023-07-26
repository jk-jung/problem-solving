def bocce_score(b):
    c = b.pop()
    a = [x for x in b if x['type'] == 'red']
    b = [x for x in b if x['type'] == 'black']

    def f(x):
        return (x['distance'][0] - c['distance'][0]) ** 2 + (x['distance'][1] - c['distance'][1]) ** 2
    s1 = sum(all(f(x) < f(y) for y in b) for x in a)
    s1 -= sum(all(f(x) < f(y) for y in a) for x in b)
    if s1 == 0: return 'No points scored'
    return f'{"black" if s1 < 0 else "red"} scores {abs(s1)}'
