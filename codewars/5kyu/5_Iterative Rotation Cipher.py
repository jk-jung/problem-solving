def rotate(s, n):
    return (s + s)[len(s) - n%len(s):][:len(s)] if len(s) > 0 else ''

def rrotate(s, n):
    return (s + s)[n%len(s):][:len(s)] if len(s) > 0 else ''

def encode(n, s):
    s = s.split(' ')

    for _ in range(n):
        t = ''.join(s)
        t = rotate(t, n)
        l = 0
        for i in range(len(s)):
            s[i] = rotate(t[l:l+len(s[i])], n)
            l += len(s[i])
    return f'{n} ' + ' '.join(s)

def decode(strng):
    n, s = strng.split(' ', 1)
    n = int(n)
    s = s.split(' ')
    for _ in range(n):
        for i in range(len(s)):
            s[i] = rrotate(s[i], n)
        t = rrotate(''.join(s), n)

        l = 0
        for i in range(len(s)):
            s[i] = t[l:l+len(s[i])]
            l += len(s[i])
    return ' '.join(s)