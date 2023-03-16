def fac(x):
    from collections import Counter
    r = Counter()
    for i in range(2, int(x ** .5) + 1):
        while x % i == 0:
            r[i] += 1
            x //= i
    if x != 1:
        r[x] = 1
    return r


def solve(a,b):
    return all(a % k == 0for k in fac(b))
