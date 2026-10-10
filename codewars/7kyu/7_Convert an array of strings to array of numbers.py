def to_float_array(x):
    def f(a):
        return float(a)
    return [f(k) for k in x]
