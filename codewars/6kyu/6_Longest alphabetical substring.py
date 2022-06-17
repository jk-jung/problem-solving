def longest(s):
    r, t = '', ''
    for x in s:
        if t == '' or t[-1] <= x:
            t += x
            if len(r) < len(t):
                r = t
        else:
            t = x
    return r
