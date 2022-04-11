def abbreviate(s):
    def f(x):
        return x if len(x) < 4 else f'{x[0]}{len(x) - 2}{x[-1]}'
    r, c = '', ''
    for x in s:
        if x.isalpha():
            c += x
        else:
            r += f(c)
            c = ''
            r += x

    return r + f(c)
