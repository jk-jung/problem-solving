def controller(e):
    st = 0
    r = '0'
    print(e)
    for x in e:
        if x == 'P':
            if st == 1: st = 2
            elif st == -1: st = -2
            elif st == 2: st = 1
            elif st == -2: st = -1
            else: st = 1 if r[-1] == '0' else -1
        elif x == 'O':
            st = -st
        a = r[-1]
        if st in (1, -1):
            a = chr(ord(a) + st)
        if a in '05': st = 0
        r += a
    return r[1:]