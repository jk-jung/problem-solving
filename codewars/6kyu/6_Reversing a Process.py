def decode(r):
    n = int(''.join(x for x in r if x.isdigit()))
    s = ''.join(x for x in r if x.isalpha())

    r = ''
    for x in s:
        ok = 0
        for i in range(26):
            if i * n % 26 == ord(x) - ord('a'):
                ok += 1
                r += chr(ord('a') + i)
        if ok != 1:
            return 'Impossible to decode'
    return r
