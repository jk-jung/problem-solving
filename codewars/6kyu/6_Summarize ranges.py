def summary_ranges(v):
    if not v: return []
    r = [[v[0] - 10] * 2]
    for x in v:
        if x <= r[-1][-1] + 1:
            r[-1][-1] = x
        else:
            r.append([x, x])
    def f(x):
        if x[0] == x[1]: return str(x[0])
        return f'{x[0]}->{x[1]}'
    return [f(x) for x in r[1:]]
