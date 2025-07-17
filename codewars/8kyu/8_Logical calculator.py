def logical_calc(a, b):
    if b == 'XOR':
        return eval('^'.join(map(str, a)))
    return all(a) if b == 'AND' else any(a)
