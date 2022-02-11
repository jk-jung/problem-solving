from collections import Counter
from math import comb


def find_mult_3(num):
    s = str(num)
    zero = s.count('0')
    m = 0

    def _go(x=1, ss='', st=0):
        nonlocal m
        r = 0
        if x == 10:
            if st != 0 or len(ss) == 0: return 0
            m = max(m, int(ss + '0' * zero))
            for i in range(zero + 1):
                r += comb(len(ss) + i - 1, i)
        else:
            for i in range(s.count(str(x)) + 1):
                r += _go(x + 1, str(x) * i + ss, (st + i * x) % 3) * comb(len(ss) + i, i)
        return r

    return [_go(), m]
