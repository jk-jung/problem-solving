from itertools import groupby
def same_length(txt):
    a = groupby(txt)
    b = []
    for k, v in a:
        b.append((k, len(list(v))))
    a = b
    if len(a) % 2: return False
    print(txt)
    for i in range(0, len(a), 2):
        x, y = a[i], a[i + 1]
        if x[0] == '0' or x[1] != y[1]: return False
    return True