def my_crib(n):
    r = []
    for i in range(n * 2 + 1):
        c = n * 2 + 1 + max(i - 1, 0) * 2
        s = c * '_'
        if i: s = f'/{s}\\'
        s = ' ' * (n * 2 - i) + s
        r.append(s)

    t = []
    for i in range(n * 2):
        if i == 0:
            s = ('|' + '_' * (n * 2 - 1)) * 3 + '|'
        elif i < n:
            s = ('|' + ' ' * (n * 2 - 1)) * 3 + '|'
        elif i == n:
            s = '|' + ' ' * (n * 2) + '_' * (n * 2 - 1) + ' ' * (n * 2) + '|'
        else:
            s = ' ' * (n * 6 - 1)
            s = f'|{s}|'
        t.append(s)
    r += reversed(t)
    r = [(x + ' ' * n * 10)[:n * 6 + 1] for x in r]
    return '\n'.join(r)