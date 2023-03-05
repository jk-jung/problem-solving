def typist(s):
    t = True
    r = len(s)
    for x in s:
        if x.isupper() and t:
            t = False
            r += 1
        if x.islower() and not t:
            t = True
            r += 1
    return r
