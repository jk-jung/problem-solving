def f(x, r = ''):
    if len(x) == 0: yield r
    for i, c in enumerate(x):
        for y in f(x[:i] + x[i + 1:], r + c): yield y


r = ''
t = {}
for i in range(0, 10):
    r += str(i)
    t[i + 1] = [''.join(x) for x in f(r)]

def nth_perm(d,n):
    return t[n][d-1]
