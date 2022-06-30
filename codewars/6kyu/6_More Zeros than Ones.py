def more_zeros(s):
    ck = set()
    def f(x):
        ck.add(x)
        x = ord(x)
        a, b = 0, 0
        while x:
            if x % 2: a += 1
            else: b += 1
            x //= 2
        return a < b
    return [x for x in s if x not in ck and f(x)]