def find_odd_names(lst):
    def f(x): return sum(map(ord, x['firstName'])) % 2
    return [x for x in lst if f(x)]
