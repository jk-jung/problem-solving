import re
from collections import Counter
def count_domains(domains, h=0):
    c = Counter()
    al = '[a-z\-0-9]'
    r = re.compile(rf'({al}*\.(?:co\.{al}{{2}}|com\.{al}{{2}}|{al}*))$')
    #     r = re.compile(r'[a-z]*\.co\.rk)$')
    for x in domains.split('\n'):
        x, cnt = x.split('\t')
        c[r.findall(x)[0]] += int(cnt)
    s = ''
    for k, v in sorted(c.items(), key=lambda x: (-x[1], x[0])):
        if v >= h: s += f"{k} ({v})\n"
    return s.strip()
