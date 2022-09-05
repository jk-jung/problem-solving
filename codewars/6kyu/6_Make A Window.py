def make_a_window(n):
    t = ('.' * n).join('|||')
    r = ['-' * (n * 2 + 3)]
    r += [t] * n
    r += ['|' + '-' * n + '+' + '-' * n + '|']
    r += [t] * n
    r += ['-' * (n * 2 + 3)]
    return '\n'.join(r)
