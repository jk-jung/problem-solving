from collections import Counter

def guess_what(n):
    c = Counter()
    for x in range(2, n + 1):
        for i in range(2, int(x ** .5) + 1):
            t = 0
            while x % i == 0:
                t += 1
                x //= i
            c[i] = max(c[i], t)
        if x != 1:
            c[x] = max(c[x], 1)

    if c: return sum(c.values())
    return 0

