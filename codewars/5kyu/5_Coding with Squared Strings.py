import math


def code(s):
    m = math.ceil(len(s) ** 0.5)
    while len(s) < m * m: s += chr(11)

    r = ''
    for x in range(m):
        for y in range(m - 1, -1, -1):
            r += s[y * m + x]
        if x != m - 1: r += '\n'

    return r


def decode(s):
    s = s.replace('\n', '')
    s = code(s).replace('\n', '')
    s = code(s).replace('\n', '')
    s = code(s).replace('\n', '')
    return s.strip()
