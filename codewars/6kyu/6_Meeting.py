def meeting(s):
    def f(x):
        x = x.split(':')
        return f'({x[1]}, {x[0]})'
    return ''.join(sorted(f(x) for x in s.upper().split(';')))
