def spin_solve(s):
    def f(x):
        p = ''
        if x[-1] in '!?.,':
            p = x[-1]
            x = x[:-1]
        if len(x) > 6 or x.lower().count('t') >= 2:
            x = ''.join(x[::-1])
        elif p == ',':
            x = x.upper()
        if len(x) == 2:
            x = x.upper()
        if len(x) == 1:
            x = '0'
        return x + p
    return ' '.join(map(f, s.split(' ')))
