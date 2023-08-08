def memorysize_conversion(a):
    a, b = a.split(' ')
    a = float(a)
    t = 1.024
    if b[0] == 'M': t = t ** 2
    if b[0] == 'G': t = t ** 3
    if b[0] == 'T': t = t ** 4
    def f(x):
        x = x.rstrip('0')
        if x[-1] == '.': x += '0'
        return x
    if 'i' in b:
        return f('%.3f' % (a * t)) + ' ' + b.replace('i', '').replace('K', 'k')
    else:
        return f('%.3f' % (a / t)) + ' ' + b[0].replace('k', 'K') + 'iB'