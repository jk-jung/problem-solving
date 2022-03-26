def stock_list(b, c):
    if not b: return ''
    def f(x):
        v = sum(int(y.split(' ')[-1]) for y in [z for z in b if z[0] == x])
        return f'({x} : {v})'
    return  ' - '.join(f(x) for x in c if f(x))
    