import re
def to_integer(s):
    r = re.match(r'^[-+]?(0b|0x|0o)?[0-9]+$', s.replace('\n', ' '))
    if not r:
        r = re.match(r'^[-+]?0x[0-9a-fA-F]+$', s.replace('\n', ' '))
        if r: return eval(r[0])
        return
    try:
        return eval(r[0])
    except:
        try:
            return int(r[0])
        except:
            return
        