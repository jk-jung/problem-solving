def kooka_counter(a):
    a = a.replace('a', '')
    r = 0
    t = ''
    for x in a:
        if x != t:
            r += 1
        t = x
    return r