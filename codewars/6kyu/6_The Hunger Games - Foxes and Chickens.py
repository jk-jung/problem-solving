import re
def hungry_foxes(s):
    a = re.sub('\[[FC\.]+\]', '$', s)
    if 'F' in a: a = a.replace('C', '.')
    def f(x):
        nonlocal a
        x = x[0]
        if 'F' in x: x = x.replace('C', '.')
        i = a.index('$')
        a = a[:i] + x + a[i + 1:]
        return x
    t = re.sub('\[[FC\.]+\]', f, s)

    return a
