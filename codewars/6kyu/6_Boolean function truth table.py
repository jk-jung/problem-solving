from inspect import signature
from itertools import product

def truth_table (f):
    sig = signature(f)
    r = [' '.join(sig.parameters.keys()) + f'\t\t{f.__name__}{str(sig).replace(" ", "")}']
    r.append('')
    for x in product(*[[False, True] for _ in range(len(sig.parameters.keys()))]):
        def t(k): return '1' if k else '0'
        r.append(' '.join(map(t, x)) + f'\t\t{t(f(*x))}')
    return '\n'.join(r).replace('<lambda>', 'f') + '\n'
