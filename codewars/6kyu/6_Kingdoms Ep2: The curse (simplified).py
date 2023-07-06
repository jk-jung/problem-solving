def translate(s, voc):
    def f(x):
        for y in voc:
            if len([c for c in x if c not in '?!,.']) != len(y): continue
            if all(c == '*' or c == d for c, d in zip(x, y)): return y + x[len(y):]
        return ''
    return ' '.join(f(x) for x in s.split(' '))
