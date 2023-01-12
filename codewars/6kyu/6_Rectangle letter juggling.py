def cipher_text(s):
    s = ''.join(x for x in s.lower() if x.isalpha())
    r = ''
    for a in range(1, len(s)):
        b = (len(s) + a - 1) // a
        if b >= a and b - a <= 1:
            for x in range(b):
                for i in range(a):
                    idx = i * b + x
                    r += s[idx] if idx < len(s) else ' '
                r += ' '
    return r[:-1]
