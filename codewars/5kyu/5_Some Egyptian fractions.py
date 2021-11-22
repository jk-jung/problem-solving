def decompose(n):
    if n == '0': return []
    if '.' in n:
        n = n.replace('.', '') + '/' + str(10 ** len(n.split('.')[-1]))
    a, b = (int(x) for x in n.split('/'))

    r = []
    if a > b:
        r.append(str(a // b))
        a %= b

    while a:
        s, e, k = 2, 2 ** 60, 2
        while s <= e:
            m = (s + e) // 2
            if a * m >= b:
                k = m
                e = m - 1
            else:
                s = m + 1

        r.append(f'{1}/{k}')
        a = a * k - b
        b *= k
    return r
