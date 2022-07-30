from collections import Counter

def encode(s):
    s = ''.join('%08d' % int(bin(ord(x))[2:]) for x in s)
    return ''.join(x * 3 for x in s)

def decode(b):
    b = ''.join(Counter(b[i:i + 3]).most_common(1)[0][0] for i in range(0, len(b), 3))
    return ''.join(chr(int(b[i:i + 8], 2)) for i in range(0, len(b), 8))