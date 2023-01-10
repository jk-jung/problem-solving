def cut_cancer_cells(s):
    r, flag, t = '', False, False
    for x in s:
        if x == 'c': t = True
        elif x == 'C':
            if r and r[-1].islower() and not t:
                r = r[:-1]
            t = True
        elif x.isupper() or not flag:
            r += x
            t = False
        else: t = True

        flag = False
        if x == 'C': flag = True
    return r
