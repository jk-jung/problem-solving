def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))

r, t = [1], 3
while len(r) < 100000:
    t += 1
    if set(list(str(t))) & {'2', '3', '5', '7'} or p(t): continue
    r.append(t)

def solve(n):
    return r[n]
