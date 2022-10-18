def check(s):
    s = ''.join(''.join(x) for x in s)
    a = s.index('q')
    b = s.index('k')
    y = abs(a // 5 - b // 5)
    x = abs(a % 5 - b % 5)
    return x == y or x == 0 or y == 0