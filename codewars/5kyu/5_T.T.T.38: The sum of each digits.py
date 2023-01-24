def f(n):
    if n < 0:return 0
    n = str(n)
    r, up, right = 0, 0, 10 ** len(n) // 10
    for i in range(len(n)):
        x = int(n[i])
        c = up + 1
        for k in range(10):
            if k == x:
                r += k * (int(n[i + 1:] or '0') + 1)
                c -= 1
            r += k * c * right
        right //= 10
        up = up * 10 + x
    return r

def sum_of_digits(a, b):
    return f(b) - f(a - 1)
