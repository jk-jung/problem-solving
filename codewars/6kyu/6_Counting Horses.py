def count_horses(s):
    r = []
    for i in range(len(s)):
        c = len([x for x in r if (i + 1) % x == 0])
        x = int(s[i]) - c
        [r.append(i + 1) for _ in range(x)]
    return r
