from itertools import product


def bindable(a, b, bs):
    aa = a.subtypes if isinstance(a.subtypes, list) else [a]
    bb = b.subtypes if isinstance(b.subtypes, list) else [b]
    if a.is_simple():
        if b.is_product(): return False
        if b.is_sum(): return any(bindable(a, x, bs) for x in b.subtypes)
        return a == b or (a, b) in bs

    if a.is_sum():
        if b.is_simple() or b.is_sum():
            return all(any(bindable(x, y, bs) for y in bb) for x in aa)
        else:
            return all(bindable(x, b, bs) for x in aa)
    else:
        if b.is_product() and len(aa) == len(bb):
            return all(bindable(x, y, bs) for x, y in zip(aa, bb))
        elif b.is_sum():
            return any(bindable(a, y, bs) for y in bb)
        return False