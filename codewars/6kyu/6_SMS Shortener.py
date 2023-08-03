def shortener(m):
    m = m.split(' ')
    while len(' '.join(m)) > 160 and len(m) >= 2:
        m = m[:-2] + [m[-2] + m[-1][0].upper() + m[-1][1:]]
    return ' '.join(m)
