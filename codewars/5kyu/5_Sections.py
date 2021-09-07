from collections import Counter

def c(k):
    cc = Counter()
    for x in range(2, int(k ** .5) + 1):
        while k % x == 0:
            cc[x] += 1
            k //= x
    if k != 1: cc[k] += 1

    r = 1
    for x in cc.values():
        print(x)
        y = x * 3 // 2
        if y * 2 != x * 3: return 0
        r *= (y + 1)
    return r