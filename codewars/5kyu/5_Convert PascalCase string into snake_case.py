import re
def to_underscore(s):
    r = ''
    for x in str(s):
        if "A" <= x <= "Z": r += '_'
        r += x.lower()

    if r[0] == '_': r = r[1:]
    return r