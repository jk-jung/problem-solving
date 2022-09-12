import re


def find(p, s):
    r = [x.span()[0] for x in re.finditer(re.escape(p).replace('_', '.'), s)] + [-1]
    return r[0]
