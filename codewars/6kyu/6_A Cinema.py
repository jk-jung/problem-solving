def cinema(b, g):
    if b < g:
        r = cinema(g, b)
        if r is None: return r
        return r.replace('G', '1').replace('B', 'G').replace('1', 'B')
    if b - g <= 1:
        return 'BG' * g + ('B' if b > g else '')
    if g == 0: return None
    r = 'G'
    g -= 1
    while b - g >= 2 and b >= 2 and g >= 1:
        b -= 2
        g -= 1
        r += 'BBG'
    if b - g <= 1: return r + cinema(b, g)
    return None
