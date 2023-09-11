from collections import Counter
def obtain_max_number(v):
    r = [0 for _ in range(5005)]
    for x in v:
        c = 1
        while x % 2 == 0:
            c *= 2
            x //= 2
        r[x] += c

    t = 0
    for i in range(1, 5001):
        if r[i]:
            t = i
        if r[i] >= 2:
            r[i * 2] += r[i] // 2
    return t
