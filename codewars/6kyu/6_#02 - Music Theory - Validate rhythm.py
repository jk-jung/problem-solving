def validate_rhythm(m, s):
    s = s.split('|')
    def f(x):
        if any(c not in '1248' for c in x): return False
        if m[1] not in [1,2,4,8]: return False
        return m[0] * 8 // m[1] == sum(8 // int(c) for c in x)
    if all(f(x) for x in s): return 'Valid rhythm'
    if len(s) > 1 and all(f(x) for x in s[1:-1] + [s[0] + s[-1]]): return 'Valid rhythm with anacrusis'
    return 'Invalid rhythm'
