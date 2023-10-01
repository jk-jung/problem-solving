def mysterious_pattern(m, n):
    a, b = 0, 1
    r = []
    for i in range(m):
        a, b = b % n, (a + b) % n
        s = [' '] * n
        s[a] = 'o'
        r.append(s)
    r = [''.join(x).rstrip() for x in zip(*r)]
    while r and not r[0].strip(): r = r[1:]
    return '\n'.join(r).rstrip()
