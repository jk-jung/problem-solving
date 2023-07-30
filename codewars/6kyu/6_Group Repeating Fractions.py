from itertools import groupby
def repeating_fractions(a, b):
    a, b = str(a / b).split('.')
    r = ''
    for x, y in groupby(b):
        r += f'({x})' if len(list(y)) > 1 else x
    return a + '.' + r
