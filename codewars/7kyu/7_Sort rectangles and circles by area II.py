import math
def sort_by_area(seq):
    def f(x):
        if isinstance(x, tuple): return x[0] * x[1]
        return x * x * math.pi
    return sorted(seq, key=f)
