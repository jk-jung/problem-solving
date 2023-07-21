def one_two_three(n):
    if not n: return [0, 0]
    r = 0
    m = n
    while m > 0:
        r = r * 10 + (9 if m >= 9 else m)
        m -= 9
    return [r, int('1' * n)]
