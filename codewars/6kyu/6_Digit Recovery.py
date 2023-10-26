def recover(s):
    r, t = '', ''
    for x in s:
        t += x
        for k, v in alph.items():
            if sorted(k) == sorted(t[-len(k):]):
                r += str(v)
    return r or 'No digits found'
