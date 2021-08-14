def gcd(a, b): return a if b == 0 else gcd(b, a % b)


def mixed_fraction(s):
    a, b = s.split('/')
    a = int(a)
    b = int(b)
    neg = 0
    if a < 0:
        a = -a
        neg ^= 1
    if b < 0:
        b = -b
        neg ^= 1

    if b == 0: a / b
    if a == 0: return '0'
    if a % b == 0: return ('' if neg == 0 else '-') + str(a // b)

    k = a // b
    a = a % b
    g = gcd(a, b)
    a //= g
    b //= g

    s = ''
    if neg: s += '-'
    if k: s += str(k) + ' '
    s += f'{a}/{b}'

    return s
