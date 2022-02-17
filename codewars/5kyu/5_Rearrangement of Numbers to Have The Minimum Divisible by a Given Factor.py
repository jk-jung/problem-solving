from itertools import permutations


def rearranger(k, *v):
    r, t = 1e100, []
    for x in permutations(v):
        s = int(''.join(str(y) for y in x))
        if s % k: continue
        if r == s:
            r = s
            t.append(x)
        elif r > s:
            r = s
            t = [x]

    t = list(sorted(list(set(t))))
    if r == 1e100: return 'There is no possible rearrangement'
    ss = ' and '.join(', '.join(str(y) for y in x) for x in t)
    return f'Rearrangement{"s" if len(t) > 1 else ""}: {ss} generates: {r} divisible by {k}'
