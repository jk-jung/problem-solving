d = [-1 for _ in range(50000)]
def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
def f(x):
    if x == 1: return 1
    if d[x] != -1: return d[x]
    d[x] = 0
    d[x] = f(sum(int(k) ** 2 for k in str(x)))
    return d[x]


def solve(a,b):
    return sum(f(x) and p(x) for x in range(a, b))
