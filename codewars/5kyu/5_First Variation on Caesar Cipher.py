def _shift(s, shift, v=1):
    t = ''
    for x in s:
        if ord('a') <= ord(x) <= ord('z'):
            x = chr((ord(x) - ord('a') + shift) % 26 + ord('a'))
        elif ord('A') <= ord(x) <= ord('Z'):
            x = chr((ord(x) - ord('A') + shift) % 26 + ord('A'))
        shift = (shift + v) % 26
        t += x
    return t

def moving_shift(s, shift):
    t = _shift(s, shift)

    n = len(s)
    m = (n + 4) // 5
    offset = 0
    r = []
    for i in range(5):
        l = min(n, m)
        r.append(t[offset:offset + l])
        offset += l
        n -= l
    return r

def demoving_shift(s, shift):
    shift = -shift % 26 + 26
    return _shift(''.join(s), shift , -1)