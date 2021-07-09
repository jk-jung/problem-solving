m = {'a': 10, 'b': 11, 'c': 12, 'd': 13, 'e': 14, 'f': 15}


def f(x):
    x = x.lower()
    if len(x) == 1: return m.get(x, int(x))
    return int(m.get(x[0], x[0])) * 16 + int(m.get(x[1], x[1]))


def hex_string_to_RGB(s):
    if len(s) == 7: return {'r': f(s[1:3]), 'g': f(s[3:5]), 'b': f(s[5:7])}
    return {'r': f(s[1]), 'g': f(s[2]), 'b': f(s[3])}
