def line_up(v):
    def f(x):
        x = x.split(' ')
        return (x[0], x[2]) if x[-1] == 'right' else (x[2], x[0])
    v = list(map(list, set(map(f, v))))

    while len(v) > 1:
        x = v[0]
        for y in v[1:]:
            if x[0] == y[1]:
                x = [y[0], *x]
                v = [x, *[z for z in v[1:] if z != y]]
                break
            elif x[-1] == y[0]:
                x = [*x, y[1]]
                v = [x, *[z for z in v[1:] if z != y]]
                break
    return v[0]
