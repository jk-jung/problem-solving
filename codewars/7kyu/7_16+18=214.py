def add(a, b):
    r = ''
    while a or b:
        r = str(a % 10 + b % 10) + r
        a //= 10
        b //= 10
    if not r: return 0
    return int(r)