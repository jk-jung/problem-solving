def arrange(a):
    def f(x):
        if 'KG' in x:
            return int(x[:-2]) * 1000
        if 'G' in x: return int(x[:-1])
        return int(x[:-1]) * 1000000
    return sorted(a, key=f)