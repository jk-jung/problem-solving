def code(s):
    r = ''
    for x in map(int, str(s)):
        x = bin(x)[2:]
        r += '0' * (len(x) - 1) + '1' + x
    return r

def decode(s):
    r, cur, i = '', 0, 0
    while i < len(s):
        cur += 1
        if s[i] == '1':
            r += str(int(s[i + 1:i + 1 + cur], 2))
            i += cur
            cur = 0
        i += 1
    return r