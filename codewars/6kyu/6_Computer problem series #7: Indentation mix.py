def autoformat(text):
    def f(x):
        c = 0
        for i in x:
            if i not in ' \t': break
            if i == ' ': c += 1
            else: c += 4 if c % 4 == 0 else 4 - c % 4
        if c % 4 < 2: c -= c % 4
        else: c += 4 - c % 4
        return ' ' * c + x.lstrip()
    return '\n'.join(map(f, text.split('\n')))
