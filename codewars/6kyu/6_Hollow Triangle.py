def hollow_triangle(n):
    r, m = [], n * 2 - 1
    for i in range(n):
        if i == n - 1:
            r.append('#' * m)
        elif i == 0:
            r.append('#'.center(m, '_'))
        else:
            a = ['_'] * (n * 2 - 1)
            a[n - i - 1] = a[n + i - 1] = '#'
            r.append(''.join(a))
    return r
