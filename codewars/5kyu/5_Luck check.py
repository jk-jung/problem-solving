def luck_check(s):
    n = len(s)
    a, b = s[:(n + 1)// 2], s[n // 2:]
    a = sum(int(x) for x in a)
    b = sum(int(x) for x in b)
    return a == b