from collections import Counter

def ck(x): return '0' not in str(x) and Counter(str(x)).most_common(1)[0][1] == 1
v = [x for x in range(1, 31427) if ck(x)]


def pow_root_pandigit(val, n, k):
    x = int(val ** (1/n))
    r = []

    for x in v:
        y = x ** n
        if y <= val or not ck(y): continue
        r.append([x, y])
        if len(r) == k: break

    return r[0] if len(r) == 1 else r
