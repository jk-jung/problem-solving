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

    v = [a, b, c, d]
    for g1 in combinations([0, 1, 2, 3], 2):
        g2 = list({0, 1, 2, 3} - set(g1))

        r1 = gen(v[g1[0]], v[g1[1]])
        r2 = gen(v[g2[0]], v[g2[1]])

        for s1, s2 in product(r1.values(), r2.values()):
            for x in ops:
                s = s1 + x + s2
                try:
                    if eval(s) == 24: return s
                except:
                    pass

        for _ in range(2):
            g2[0], g2[1] = g2[1], g2[0]
            v1 = v[g2[0]]
            v2 = v[g2[1]]

            for x in ops:
                for y in ops:
                    for t in r1.values():
                        ss = [
                            f'({t}{x}{v1}){y}{v2}',
                            f'({v1}{x}{t}){y}{v2}',
                            f'{v2}{y}({t}{x}{v1})',
                            f'{v2}{y}({v1}{x}{t})',
                        ]

                        for s in ss:
                            try:
                                if eval(s) == 24: return s
                            except:
                                pass

    return "It's not possible!"
