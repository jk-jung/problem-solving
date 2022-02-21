n = 5000000
p = [0 for _ in range(n + 1)]
c = [0 for _ in range(n + 1)]
d = [0 for _ in range(n + 1)]

for i in range(2, n + 1):
    if p[i] == 0:
        for j in range(i + i, n + 1, i):
            p[j] = 1
        x = i
        while x:
            if x % 2 == 0: c[i] += 1
            x //= 10

for i in range(2, n + 1):
    if p[i] == 0:
        d[i] = i
    if c[d[i]] < c[d[i - 1]]:
        d[i] = d[i - 1]

def f(n):
    return d[n - 1]
