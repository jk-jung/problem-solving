def f(s): return [list(x) for x in s.split('\n')], len(s.split('\n'))
def g(s): return '\n'.join([''.join(x) for x in s])
def rot_90_clock(s):
    s, n = f(s)
    return g([s[n - j - 1][i] for j in range(n)] for i in range(n))


def diag_1_sym(s):
    s, n = f(s)
    return g([s[j][i] for j in range(n)] for i in range(n))


def selfie_and_diag1(s):
    a, n = f(s)
    b, n = f(diag_1_sym(s))
    return '\n'.join([''.join(x) + '|' + ''.join(y) for x, y in zip(a, b)])


def oper(f, s):
    return f(s)
