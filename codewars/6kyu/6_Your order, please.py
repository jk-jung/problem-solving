def order(w):
    if w == '': return w
    def f(t): return max(int(x) for x in t if x.isnumeric())
    return ' '.join(sorted([x for x in w.split(' ')], key=f))
