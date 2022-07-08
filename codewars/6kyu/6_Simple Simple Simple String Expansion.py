def string_expansion(s):
    r, t, k = '', '', 1
    s += '0'
    for x in s:
        if x.isdigit():
            r += ''.join(y * k for y in t)
            t = ''
            k = int(x)
        else:
            t += x
    return r