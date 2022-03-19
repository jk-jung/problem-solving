def diamond(n):
    if n < 0 or n % 2 == 0: return None
    if n == 1: return '*\n'
    r = []
    for x in range(1, n, 2):
        r.append(' ' * ((n - x) // 2) + '*' * x)
    s = '\n'.join(r) + '\n' + n * '*' + '\n'
    s += '\n'.join(reversed(r))
    return s.rstrip() + '\n'
