def string_color(s):
    if len(s) <= 1: return
    a = sum(map(ord, s))
    b = 1
    c = abs(a - ord(s[0]) * 2)
    for x in s: b *= ord(x)

    def h(x): return ('00' + hex(x % 256)[2:])[-2:].upper()
    return h(a) + h(b) + h(c)