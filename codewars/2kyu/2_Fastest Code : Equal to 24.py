from itertools import combinations, product


def equal_to_24(a, b, c, d):
    ops = '+-*/'

    def gen(a, b):
        r = {}
        for x in ops:
            for _ in range(2):
                a, b = b, a
                s = f'({a}{x}{b})'
                r[eval(s)] = s
        return r

    def calc(a, b, op):
        if op == '+': return a + b
        if op == '-': return a - b
        if op == '*': return a * b
        return a / b

    v = [a, b, c, d]
    for g1 in combinations([0, 1, 2, 3], 2):
        g2 = list({0, 1, 2, 3} - set(g1))

        r1 = gen(v[g1[0]], v[g1[1]])
        r2 = gen(v[g2[0]], v[g2[1]])

        for s1, s2 in product(r1.keys(), r2.keys()):
            for x in ops:
                try:
                    if calc(s1, s2, x) == 24: return r1[s1] + x + r2[s2]
                except:
                    pass

        for _ in range(2):
            g2[0], g2[1] = g2[1], g2[0]
            v1 = v[g2[0]]
            v2 = v[g2[1]]

            r2 = {}
            for v0, s0 in r1.items():
                for x in ops:
                    try: r2[calc(v0, v1, x)] = f'({s0}{x}{v1})'
                    except: pass
                    try: r2[calc(v1, v0, x)] = f'({v1}{x}{s0})'
                    except: pass

            if 24 - v2 in r2:
                return r2[24 - v2] + '+' + str(v2)
            if 24 + v2 in r2:
                return r2[24 + v2] + '-' + str(v2)
            if v2 - 24 in r2:
                return str(v2) + '-' + r2[v2 - 24]
            if 24 / v2 in r2:
                return r2[24 / v2] + '*' + str(v2)
            if 24 * v2 in r2:
                return r2[24 * v2] + '/' + str(v2)
            if v2 / 24 in r2:
                return str(v2) + '/' + r2[v2 / 24]

    return "It's not possible!"