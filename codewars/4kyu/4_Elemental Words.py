d = {}
def go(left):
    if left == '': return [[]]
    if left in d: return d[left]

    r = []
    for k in ELEMENTS:

        if k.lower() == left[:len(k)].lower():
            [r.append([k] + x) for x in go(left[len(k):])]
    d[left] = r
    return r


def refine(t):
    return [f'{ELEMENTS[x]} ({x})' for x in t]


def elemental_forms(word):
    return [refine(x) for x in go(word)]