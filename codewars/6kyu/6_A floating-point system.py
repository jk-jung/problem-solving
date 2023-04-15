import numpy
def mant_exp(n, d):
    n = numpy.format_float_positional(n)
    t = len(n.split('.')[-1])
    n = n.replace('.', '')
    while n[0] == '0':n = n[1:]
    while len(n) < d:
        n += '0'
        t += 1
    k = len(n) - d
    if k:
        n = n[:-k]
        t -= k
    return f'{n}P{-t}'
