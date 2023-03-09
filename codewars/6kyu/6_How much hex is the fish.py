def fisHex(s):
    r = 0
    for x in s.lower():
        if x in 'abcdef':
            r ^= (ord(x) - ord('a') + 10)
    return r
