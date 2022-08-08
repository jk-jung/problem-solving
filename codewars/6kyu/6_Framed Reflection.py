def mirror(t):
    t = t.split(' ');
    n = max(map(len, t))
    r = '\n'.join('* %s%s *' % (x[::-1], ' ' * (n - len(x))) for x in t if x)
    return '\n'.join(['*' * (n + 4), r, '*' * (n + 4)])
