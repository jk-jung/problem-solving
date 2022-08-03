def is_odd_heavy(v):
    a = [x for x in v if x % 2]
    b = [x for x in v if x % 2 == 0]

    if not a and not b: return False
    if not b: return True
    if not a: return False
    return min(a) > max(b)