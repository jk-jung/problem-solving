ans = ["AA", "AB", "AD", "AE", "AG", "AH", "AI", "AL", "AM", "AN", "AR", "AS", "AT", "AW", "AX", "AY", "BA", "BE", "BI", "BO", "BY", "CH", "DA", "DE", "DI", "DO", "EA", "ED", "EE", "EF", "EH", "EL", "EM", "EN", "ER", "ES", "ET", "EW", "EX", "FA", "FE", "FY", "GI", "GO", "GU", "HA", "HE", "HI", "HM", "HO", "ID", "IF", "IN", "IO", "IS", "IT", "JA", "JO", "KA", "KI", "KO", "KY", "LA", "LI", "LO", "MA", "ME", "MI", "MM", "MO", "MU", "MY", "NA", "NE", "NI", "NO", "NU", "NY", "OB", "OD", "OE", "OF", "OH", "OI", "OK", "OM", "ON", "OO", "OP", "OR", "OS", "OU", "OW", "OX", "OY", "PA", "PE", "PI", "PO", "QI", "RE", "SH", "SI", "SO", "ST", "TA", "TE", "TI", "TO", "UG", "UH", "UM", "UN", "UP", "UR", "US", "UT", "WE", "WO", "XI", "XU", "YA", "YE", "YO", "YU", "ZA", "ZE", "ZO"]
score = [1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10]
alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def crossword_2x2(v):
    s = list(v[0] + v[1])
    r = []
    def sc(x): return score[alpha.index(x[0])] + score[alpha.index(x[1])]
    def go(i):
        if i == 4:
            w = [s[0] + s[1], s[2] + s[3], s[0] + s[2], s[1] + s[3]]
            w = list(x for x in w if x in ans)
            if len(set(w)) != 2: return
            r.append((w[0], w[1], sc(w[0]) + sc(w[1])))
        else:
            if s[i] == '_':
                for x in alpha:
                    s[i] = x
                    go(i + 1)
                s[i] = '_'
            else: go(i+1)

    go(0)
    return sorted(r, key=lambda x: (-x[2], x[0], x[1]))
