def my_crib(n):
    m = n * 2 + 2
    r = []
    for i in range(n + 1):
        s = '/' + (' ' if i < n else '_') * 2 * i + '\\'
        r.append(s.center(m))
    for i in range(n):
        r.append('|' + (' ' if i < n - 1 else '_') * (m - 2) + '|')
    return '\n'.join(r)
