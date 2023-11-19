def odd(s):
    r = 0
    while True:
        a = s.find('o')
        b = s.find('d', a)
        c = s.find('d', b + 1)
        if -1 in {a, b, c}: break
        s = list(s)
        s[a] = s[b] = s[c] = '_'
        s = ''.join(s)
        r += 1
    return r
