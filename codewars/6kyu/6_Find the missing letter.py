def find_missing_letter(v):
    flag, v = False, ''.join(v)
    flag2 = v[0].isupper()

    for a in 'abcdefghijklmnopqrstuvwxyz':
        if a in v.lower(): flag = True
        elif flag: return a.upper() if flag2 else a
