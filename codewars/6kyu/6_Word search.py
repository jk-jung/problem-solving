def index_of(v, x):
    s, e = 0, len(v) - 1

    def f(z): return (len(z), -len([k for k in z if k.isupper()]), z)
    while s <= e:
        m = (s + e) // 2
        y = v[m]

        if f(y) == f(x):
            return m
        elif f(y) < f(x): s = m + 1
        else: e = m - 1
