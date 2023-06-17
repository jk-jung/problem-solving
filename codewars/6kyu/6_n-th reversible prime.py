def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
r, x = [2, 3, 5, 7], 11
while len(r) < 10000:
    if p(x) and p(int(str(x)[::-1])):
        r.append(x)
    x += 1

def reversible_prime(n):
    return r[n]