def sort_ranks(ranks):
    def f(x): return [int(y) for y in x.split('.')]
    return sorted(ranks, key=f)
