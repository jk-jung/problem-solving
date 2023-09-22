import re
def remove(s):
    while True:
        ok = True
        x = re.findall(r'(\!+|\?+)', s)
        r = ''
        for y in x:
            if len(y) % 2 and len(y) > 1:
                ok = False
            else:
                r += y
        s = r
        if ok:
            break
    return s
