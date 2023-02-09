def grille(m, c):
    m = m[::-1]
    r = ''
    for i in range(len(m)):
        if c >> i & 1:
            r += m[i]
    return r[::-1]
