def expanded_form(n):
    n = str(n)
    if '.' not in n: n += '.'
    k = n.find('.')

    r = []
    for i, x in enumerate(n):
        if x == '0' or x == '.': continue
        if i < k: r.append(x + '0' * (k - i - 1))
        else: r.append(f'{x}/1' + '0' * (i - k))
    return ' + '.join(r)
