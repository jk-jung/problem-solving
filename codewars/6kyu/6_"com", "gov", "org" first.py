def order_by_domain(v):
    def f(x):
        t = x.split('.')[-1].split('/')[0]
        return ({'com': 0, 'gov': 1, 'org': 2}.get(t, 3), t)
    return sorted(v, key=f)
