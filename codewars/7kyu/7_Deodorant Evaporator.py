def evaporator(a, b, c):
    r = 0
    c = a * c / 100
    while a >= c:
        a *= (100 - b) / 100
        r += 1
    return r
