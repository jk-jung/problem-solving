def cat_mouse(x,j):
    c, d, m = x.find('C'), x.find('D'), x.find('m')
    if min(c, d, m) == -1:
        return 'boring without all three'

    if abs(c - m) <= j:
        return 'Protected!' if min(c, m) < d < max(c, m) else 'Caught!'
    return 'Escaped!'
