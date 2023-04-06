from itertools import groupby

def group_cities(v):
    def g(x):
        x.append(x.pop(0))
        return ''.join(x)
    def f(x): return sorted(g(x) for _ in range(len(x)))[0]
    v = sorted([(f(list(x.lower())), x) for x in v])
    v = [sorted({y[1] for y in x[1]}) for x in groupby(v, key=lambda x: x[0])]

    return sorted(v, key=lambda x: (-len(x), x[0]))
