def exchange_with(a, b):
    c, d = a[::-1], b[::-1]
    a.clear()
    b.clear()
    a += d
    b += c
