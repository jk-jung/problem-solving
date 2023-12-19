def encode(s):
    r = []
    for x in s:
        if x == ' ':r.append('... ... ...')
        else:
            x = ord(x) - ord('A')
            i = x % 3 + 1
            j = x // 3 % 3 + 1
            k = x // 9 + 1
            r.append('.' * i + ' ' + '.' * j + ' ' + '.' * k)
    return ' '.join(r)


def decode(s):
    s = [len(x) for x in s.split(' ')]
    r = ''
    for i in range(0, len(s), 3):
        x = (s[i+2] - 1) * 9 + (s[i+1] - 1) * 3 + s[i] - 1
        r += chr(ord('A') + x)
    return r.replace('[', ' ')
