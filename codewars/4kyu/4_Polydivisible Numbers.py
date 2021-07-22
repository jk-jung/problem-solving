CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"


def is_polydivisible(s, b):
    v = 0
    for i in range(len(s)):
        v = v * b + CHARS.find(s[i])
        if v % (i + 1) != 0: return False
    return True


def to_base(x, b):
    r = ''
    while x:
        r = CHARS[x % b] + r
        x //= b
    return r if r else '0'


def get_polydivisible(n, b):
    i = -1
    while n:
        i += 1
        v = to_base(i, b)
        if is_polydivisible(v, b):
            n -= 1
    return v
