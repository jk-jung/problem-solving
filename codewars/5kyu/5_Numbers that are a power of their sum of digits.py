MAX = 1e20
r = []
for i in range(2, 200):
    x = i * i
    while x < MAX:
        if sum(int(y) for y in str(x)) == i:
            r.append(x)
        x *= i

r.sort()


def power_sumDigTerm(n):
    return r[n - 1]
