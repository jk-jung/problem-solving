from datetime import date
from itertools import product

def check_dates(records):
    def gen(x):
        y, m, d = map(int, x.split('-'))
        try: yield date(year=y,month=m,day=d)
        except: pass
        try: yield date(year=y,month=d,day=m)
        except: pass

    r = [0, 0, 0]
    for s, e in records:
        t = list(dict.fromkeys(product(gen(s), gen(e))))
        ok = [a <= b for a, b in t]
        if sum(ok) >= 2: r[2] += 1
        elif sum(ok) == 1:
            if ok[0]: r[0] += 1
            else: r[1] += 1
        else:
            print(s, e)
            raise Exception()

    return r
