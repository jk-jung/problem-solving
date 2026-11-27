def split_in_parts(s, a):
    r = ''
    for i, x in enumerate(s):
        r += x
        if i % a == a - 1:r += ' '
    return r.strip()