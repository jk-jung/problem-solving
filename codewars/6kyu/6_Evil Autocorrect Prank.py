import re
def autocorrect(s):
    r1 = re.compile('^(u)([^a-z]*)$')
    r2 = re.compile('^(you+)([^a-z]*)$')

    r = []
    for x in s.split(' '):
        y = x.lower()
        m = r1.match(y) or r2.match(y)
        if m:
            r.append(f'your sister{m[2]}')
        else:
            r.append(x)
    return ' '.join(r)
