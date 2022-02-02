import re
def derivative(eq):
    r = re.compile(r'([-\+]?[0-9]*)(x?)(\^[0-9]+)?').finditer(eq)

    s = ''
    for x in r:
        if x[0] == '' or x[2] == '': continue
        a, t, b = x[1], x[2], x[3]

        if a == '-': a = -1
        elif a == '' or a == '+': a = 1
        else: a = int(a)

        if b is None: b = 1
        else: b = int(b[1:])

        k = a * b
        if k >= 0 and len(s) > 0: s += '+'
        s += f'{k}'
        if b == 2: s += 'x'
        elif b > 1: s += f'x^{b - 1}'

    if s == '': s = '0'
    return s
