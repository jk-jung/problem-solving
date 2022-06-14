def rot(s):
    return '\n'.join(x[::-1] for x in s.split('\n')[::-1])

def selfie_and_rot(a):
    n = len(a.split('\n'))
    b = rot(a)
    return '\n'.join(
        [x + '.' * n for x in a.split('\n')] +
        ['.' * n + x for x in b.split('\n')]
    )

def oper(f, s):
    return f(s)