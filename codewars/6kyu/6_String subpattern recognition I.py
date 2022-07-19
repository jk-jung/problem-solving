def has_subpattern(s):
    if len(s) == 1: return False
    n = len(s)
    for i in range(1, n):
        if n % i: continue
        if len(set(s[x: x + i] for x in range(0, n, i))) == 1:
            return True
    return False