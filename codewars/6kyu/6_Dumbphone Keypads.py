N = {
    '1': '1',
    '2': 'ABC2',
    '3': 'DEF3',
    '4': 'GHI4',
    '5': 'JKL5',
    '6': 'MNO6',
    '7': 'PQRS7',
    '8': 'TUV8',
    '9': 'WXYZ9',
    '0': ' 0',
    '*': '*',
    '#': '#',
}
def sequence(s):
    r = ' '
    for x in s.upper():
        for k, v in N.items():
            if x in v:
                if k == r[-1]: r += 'p'
                r += k * (v.index(x) + 1)
    return r[1:]