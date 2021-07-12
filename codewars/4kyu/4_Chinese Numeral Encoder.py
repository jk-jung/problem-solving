def to_chinese_numeral(n):
    numerals = {
        "-": "负",
        ".": "点",
        0: "零",
        1: "一",
        2: "二",
        3: "三",
        4: "四",
        5: "五",
        6: "六",
        7: "七",
        8: "八",
        9: "九",
    }
    bases = {
        1: '',
        10: "十",
        100: "百",
        1000: "千",
        10000: "万"
    }

    r = ''
    if n < 0:
        r = numerals['-']
        n = -n

    if '.' in str(n):
        a, b = str(n).split('.')
        z = ''.join(numerals[int(x)] for x in b)
        r += to_chinese_numeral(int(a)) + numerals['.'] + z
    else:
        base = 10000
        rr = ''

        while base > 0:
            t = n // base

            if t == 1 and rr == '' and base == 10:
                rr += bases[base]
            elif t == 0 and rr != '':
                rr += numerals[0]
            elif t > 0:
                rr += numerals[t] + bases[base]

            n %= base
            base //= 10
        rr = rr.strip(numerals[0])
        for _ in range(10): rr = rr.replace(numerals[0] * 2, numerals[0])
        if rr == '': rr = numerals[0]
        r += rr
    return r
