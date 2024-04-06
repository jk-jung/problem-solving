def is_multiple(a, b, n):
    a = a % b
    r = 0
    i = 0
    while True:
        a *= 10
        r = r * 10 + a // b
        a %= b
        i += 1
        if i == 2:break
    if r % 10 >= 5: r += 10
    r //= 10
    if r % 10 == 0:return False
    return r % n == 0
