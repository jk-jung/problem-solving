def convert(s):
    ck = {}
    r = ''
    for x in s.lower():
        if x not in ck:
            if len(ck) == 1: ck[x] = '0'
            elif len(ck) == 0: ck[x] = '1'
            else: ck[x] = str(len(ck))
        r += ck[x]
    return int(r or '0')