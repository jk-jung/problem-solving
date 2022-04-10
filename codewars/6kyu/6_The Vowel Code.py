m = 'aeiou'

def encode(s):
    return ''.join(str(m.index(x) + 1) if x in m else x for x in s)

def decode(s):
    return ''.join(m[int(x) - 1] if x.isdigit() else x for x in s)