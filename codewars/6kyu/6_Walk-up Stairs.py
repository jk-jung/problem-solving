def stairs(n):
    if n < 1: return ''
    m = 0
    r = []
    for i in range(n, 0, -1):
        s = ' '.join(str(x % 10) for x in range(1, i + 1))
        s = s + ' ' + s[::-1]
        m = max(m, len(s))
        s = ' ' * (m - len(s)) + s
        r.append(s)
    return '\n'.join(r[::-1])