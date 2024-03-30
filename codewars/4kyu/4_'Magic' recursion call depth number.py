import re

def f(x):
    return set(re.findall('P(\d+)', x))

def magic_call_depth_number(s):
    print(s)
    pat = r'p(\d+)([FLRP0-9]+)q'
    res = dict([(k, f(v)) for k, v in re.findall(pat, s)])
    s = s = re.sub(pat, '', s)

    dep = 0
    vis = set()
    def go(x):
        if x in vis: return (0, 0)
        vis.add(x)
        if not res[x]:
            vis.remove(x)
            return -1, -1

        tt = [go(y) for y in res[x]]
        aa = sorted([y[0] for y in tt])
        bb = sorted([y[1] for y in tt])

        vis.remove(x)
        return (
            aa[0] if aa[0] == -1 else aa[0] + 1,
            bb[-1] if bb[-1] == -1 else bb[-1] + 1
        )

    a = 1 << 30
    b = -1
    for x in [x for x in s.split('P') if x]:
        dep = 0
        vis = set()
        t = go(x)
        a = min(a, t[0])
        b = max(b, t[1])
    if a == -1 or a == 1073741824: a = 0
    if b == -1: b = 0

    return [a, b]
