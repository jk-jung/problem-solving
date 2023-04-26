def bits_war(n):
    r = 0
    for x in n:
        if x == 0:continue
        t = bin(x).count('1') * x // abs(x)
        if x % 2 == 0: r += t
        else: r -= t
    if r == 0: return 'tie'
    return 'odds win' if r < 0 else 'evens win'
