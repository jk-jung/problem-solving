import re
def frame(s):
    t = blz
    ss = '|'.join(blz.keys())
    r = sum(t[x[0]] * int(x[1] or 1) for x in re.findall(rf'({ss})(\d*)', s))
    if 'W' in s: return 'Foul'
    if r > 147: return 'invalid data'
    return r
