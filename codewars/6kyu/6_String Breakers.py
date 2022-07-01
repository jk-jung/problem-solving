def string_breakers(n, s):
    s = s.replace(' ', '')
    return '\n'.join(s[x: x + n] for x in range(0, len(s), n))