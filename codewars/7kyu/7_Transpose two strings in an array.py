def transpose_two_strings(v):
    a, b = v
    r = ''
    for i in range(max(len(a), len(b))):
        r += a[i] if i < len(a) else ' '
        r += ' '
        r += b[i] if i < len(b) else ' '
        r += '\n'
    return r[:-1]
