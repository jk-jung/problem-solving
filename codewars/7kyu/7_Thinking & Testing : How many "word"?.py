def testit(s):
    t = 'word'
    i = 0
    r = 0
    for x in s.lower():
        if x == t[i % 4]:
            i += 1
            if i % 4 == 0:
                r += 1
    return r
