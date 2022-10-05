from collections import Counter
def find_duplicate_phone_numbers(v):
    def f(s):
        r = ''
        for x in s.upper():
            if x.isdigit(): r += x
            if x in 'ABC': r += '2'
            if x in 'DEF': r += '3'
            if x in 'GHI': r += '4'
            if x in 'JKL': r += '5'
            if x in 'MNO': r += '6'
            if x in 'PRS': r += '7'
            if x in 'TUV': r += '8'
            if x in 'WXY': r += '9'
        return r
    v = Counter(f(x) for x in v)
    return [f"{k[:3]}-{k[3:]}:{v}" for k, v in sorted(v.items()) if v > 1]
