def find_secret_message(v):
    a, b = set(), set()
    r = []
    for x in v.split(' '):
        x = ''.join([y for y in x if y.isalpha() or y == '-'])
        z = x.lower()
        if z not in a:a.add(z)
        elif z not in b:
            r.append(z)
            b.add(z)
    return ' '.join(r)
