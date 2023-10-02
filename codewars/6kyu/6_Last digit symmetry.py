def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
def solve(a, b):
    r = 0
    for x in range(a, b):
        y = x * x
        if x % 100 != y % 100: continue
        if not p(int(str(x)[:2])): continue
        if not p(int(str(y)[:2])): continue
        r += 1
    return r
