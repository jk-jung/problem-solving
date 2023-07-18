def check_tombola(s):
    if [len(x) for x in s] != [9, 9, 9]: return False
    if [len([x for x in y if x]) for y in s] != [5, 5, 5]: return False
    t = [x for x in sum(s, []) if x]
    if len(t) != len(set(t)): return False

    for i, v in enumerate(zip(*s)):
        v = [x for x in v if x]
        if sorted(v) != v or not v: return False
        s = i * 10
        e = s + (10 if i == 8 else 9)
        if not all(s <= x <= e for x in v): return False
    return True
