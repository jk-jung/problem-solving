def to_bcd(n):
    if not n: return '0000'
    t = ''
    if n < 0:
        n = -n
        t = '-'
    r = []
    while n:
        x = n % 10
        r.append(('0'* 10 + bin(x)[2:])[-4:])
        n //= 10
    return t + ' '.join(r[::-1])