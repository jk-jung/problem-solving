def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
sz = 15000002
r = [0 for _ in range(sz)]
p = [0 for _ in range(sz)]
r[1] = 1
for j in range(4, sz, 2): p[j] = 1
for i in range(3, sz, 2):
    r[i - 1] = r[i - 2]
    r[i] = r[i-1]
    if p[i]: continue
    x = i - 1
    while x % 2 == 0:x //= 2
    while x % 3 == 0:x //= 3
    if x == 1:r[i] += 1
    for j in range(i + i, sz, i): p[j] = 1
r[1] = 0
r[-1] = 0
def solve(x, y):
    return r[y - 1] - r[x - 1]
