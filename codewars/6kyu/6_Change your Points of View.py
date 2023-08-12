def point(a, b):
    return lambda x: a if x else b

def fst(a):
    return a(1)

def snd(a):
    return a(0)

def sqr_dist(a, b):
    x = a(1) - b(1)
    y = a(0) - b(0)
    return x ** 2 + y ** 2

def line(a, b):
    x = a(1) - b(1)
    y = a(0) - b(0)
    return [y, -x, x * a(0) - y * a(1)]
