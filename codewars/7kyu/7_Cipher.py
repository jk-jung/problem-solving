def encode(t):
    return ''.join(chr(ord(x) * 6) for x in t)


def decode(t):
    return ''.join(chr(ord(x) // 6) for x in t)
