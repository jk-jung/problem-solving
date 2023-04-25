def sort_two_arrays(a, b):
    def f(x, y):
        z = sorted([(k, i) for i, k in enumerate(y)])
        return [x[i[1]] for i in z]
    return [f(a, b), f(b, a)]
