def check(a, b):
    if len(a) != len(b): return False
    t = { x: y for x, y in zip(a, b)}
    return all(t[x] == y for x, y in zip(a, b))

def isomorph(a, b):
    return check(a, b) and check(b, a)
