from fractions import Fraction

m = 1500
d = [[0 for _ in range(m + 5)] for _ in range(m + 5)]
d[0][0] = d[0][1] = 1
for i in range(1, m - 2):
    for j in range(i + 2):
        if j == 0:
            d[i][j] = 1
        else:
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j]
r = [Fraction(0, 1) for _ in range(m)]
r[1] = Fraction(-1, 2)

for i in range(2, m - 2):
    if i % 2 == 1:
        r[i] = 0
    else:
        t = Fraction(-1, 1)
        for j in range(1, i):
            t -= r[j] * d[i][j]
        r[i] = t / d[i][i]


def bernoulli_number(n):
    if not n: return 1
    return r[n]
