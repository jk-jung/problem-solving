from itertools import groupby
def send(s):
    s = ''.join(bin(ord(x))[2:].zfill(7) for x in s)
    r = []
    for x, y in groupby(s):
        r.append('0' * (2 - int(x)))
        r.append('0' * len(list(y)))
    return ' '.join(r)

def receive(s):
    s = s.split(' ')
    r = ''
    for i in range(0, len(s), 2):
        x, y = s[i:i+2]
        r += ('1' if x == '0' else '0') * len(y)
    return ''.join(chr(int(r[i:i+7], 2)) for i in range(0, len(r), 7))
