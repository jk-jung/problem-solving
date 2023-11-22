def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))

t = []
c = 0
for i in range(2, 500005):
    if p(i):
        c += 1
        if p(c):t.append(i)

def solve(a, b):
    return sum([x for x in t if a <=x <=b])