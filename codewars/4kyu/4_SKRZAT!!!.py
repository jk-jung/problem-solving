def d2(number):
    b = 1
    r = 0
    for i in reversed(number):
        if i == '1': r += b
        b *= -2
    return r


d10 = {}
for i in range(1 << 16):
    b = '{0:b}'.format(i)
    d10[d2(b)] = b


def skrzat(base, number):
    if base == 'b':
        return f'From binary: {number} is {d2(number)}'
    else:
        return f'From decimal: {number} is {d10[number]}'
