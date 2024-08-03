def f(x):
    return (x & (x - 1)) == 0


def operation(a, b):
    r = 0
    while not f(a):
        a >>= 1
        r +=1
    while a < b:
        a <<= 1
        r += 1
    while a > b:
        a >>= 1
        r += 1
    return r
