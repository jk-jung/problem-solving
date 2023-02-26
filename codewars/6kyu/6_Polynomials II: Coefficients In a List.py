def calc_poly(v, x): #If polynomial degree == 3
    n = len(v)
    r = ' + '.join([f'{v[i]}*x^{ n - i - 1}' for i in range(n) if v[i]]) + ' '
    r = r.replace('*x^0', '').replace('x^1 ', 'x ').replace('-1*x', '-x').replace(' + -', ' - ').replace(' 1*x', 'x').replace('+x', '+ x').strip()
    if r.startswith('- '): r = '-' + r[2:]
    if r.startswith('1*'): r = r[2:]
    return f"For {r} with x = {x} the value is {eval(r.replace('^', '**'))}"
