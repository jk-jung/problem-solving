from math import comb

cur = {0}
st = {0}
r = [1]
for i in range(10000000):
    if len(st) == 49:
        r.append(r[-1] + 49)
    else:
        nt = set()
        for x in st:
            for k in (4, 9, 49):
                if x + k not in cur:
                    cur.add(x + k)
                    nt.add(x + k)
        r.append(len(cur))
        st = nt

def solve(n):
    return r[n]
