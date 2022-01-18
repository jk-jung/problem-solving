def word_wrap(t, n):
    t = t.split(' ')
    r = ['1' * n]

    for x in t:
        if len(r[-1] + ' ' + x) <= n:
            r[-1] += ' ' + x
        elif len(x) <= n:
            r.append(x)
        else:
            s = n - len(r[-1]) - 1
            if s > 0:
                r[-1] += ' ' + x[:s]
            else:
                s = 0
            r += [x[i:i+n] for i in range(s, len(x), n)]
    return '\n'.join(r[1:])