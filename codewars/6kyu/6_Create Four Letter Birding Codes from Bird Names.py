def bird_code(v):
    r = []
    for x in v:
        x = x.replace('-', ' ').replace('_', ' ').split(' ')
        if len(x) == 1: r.append(x[0][:4])
        elif len(x) == 2: r.append(x[0][:2] + x[1][:2])
        elif len(x) == 3: r.append(x[0][0] + x[1][0] + x[2][:2])
        else: r.append(''.join(y[0] for y in x))
    return [x.upper() for x in r]
