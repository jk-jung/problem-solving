m = 40000000
s = 0
d = [0]
while s < 40000000:
    s += len(d)
    d.append(s)

def same_col_seq(val, k, col):
    c = {'red': 1, 'yellow': 2, 'blue':0}[col]
    r = []
    for i, x in enumerate(d):
        if x <= val: continue
        if x % 3 == c:
            r.append(x)
    return r[:k]