from collections import Counter


def vertical_histogram_of(s):
    c = Counter([x for x in s if 'A' <= x <= 'Z'])
    k = sorted(c.keys())
    if len(k) == 0: return ''

    r = ''
    for i in range(max(c.values()), 0 , -1):
        t = ''
        for x in k:
            t += '  ' if c[x] < i else '* '
        r += t.rstrip() +'\n'
    r += ' '.join(k)
    return r