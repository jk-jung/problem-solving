def rocks(n):
    r, base, c = 0, 1, 1
    while base <= n:
        if n >= base * 10 - 1:
            r += c * base * 9
            print(c * base * 9)
        else:
            r += (n % (base * 10) - base + 1) * c
        c += 1
        base *= 10
    return r
