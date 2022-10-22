def x(n):
    r = ''
    for i in range(n):
        for j in range(n):
            r += '■' if i == j or n - i - 1 == j else '□'
        r += '\n'
    return r.strip()
