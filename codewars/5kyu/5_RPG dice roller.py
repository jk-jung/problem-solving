import re
import random


def roll(x, verbose=False):
    if not isinstance(x, str): return False
    x = x.replace(' ', '')

    reg = re.compile(r'^(\d*)d(\d+)(([+-]\d+)*)$')
    m = reg.match(x)
    if m is None: return False

    cnt = int(m[1]) if len(m[1]) > 0 else 1
    r = {
        'dice': [random.randint(1, int(m[2])) for _ in range(cnt)],
        'modifier': eval(m[3]) if m[3] else 0
    }

    return r if verbose else sum(r['dice']) + r['modifier']
