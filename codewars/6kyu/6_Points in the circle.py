r = [0 for i in range(2000001)]
n = 1000
for x in range(-n, n + 1):
    for y in range(-n, n + 1):
        r[x ** 2 + y ** 2] += 1

for i in range(1, 2000001):
    r[i] += r[i - 1]


def points(n):
    return r[n ** 2]
