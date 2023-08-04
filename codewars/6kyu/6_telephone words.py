from itertools import product
def telephone_words(v):
    N = {
        '1': '1',
        '2': 'ABC',
        '3': 'DEF',
        '4': 'GHI',
        '5': 'JKL',
        '6': 'MNO',
        '7': 'PQRS',
        '8': 'TUV',
        '9': 'WXYZ',
        '0': '0'
    }
    return [''.join(x) for x in product(*[N[x] for x in v])]
