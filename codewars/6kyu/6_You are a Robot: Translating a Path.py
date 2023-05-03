from itertools import groupby
def walk(s):
    if not s: return "Paused"
    t = {
        '^': 'up',
        'v': 'down',
        '>': 'right',
        '<': 'left',
    }
    r = []
    for k, v in groupby(s):
        v = len(list(v))
        r.append(f"Take {v} step{'s' if v >= 2 else ''} {t[k]}")
    return '\n'.join(r)
