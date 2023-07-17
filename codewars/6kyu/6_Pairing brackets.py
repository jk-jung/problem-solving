def bracket_pairs(s):
    r = []
    t = []
    for i, x in enumerate(s):
        if x == '(': r.append(i)
        elif x == ')':
            if not r: return False
            t.append([r.pop(), i])
    return False if r else dict(t)
