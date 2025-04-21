def highest_value(a, b):
    def f(y): return sum(ord(x) for x in y)
    return a if f(a) >= f(b) else b