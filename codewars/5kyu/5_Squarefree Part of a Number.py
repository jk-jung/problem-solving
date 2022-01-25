def square_free_part(n):
    if type(n) != type(1): return None
    if n <= 0: return None
    if n == 1: return 1

    r = 1
    c = 2
    while c * c <= n:
        if n % c == 0: r *= c
        while n % c == 0: n //= c
        c += 1

    r *= n
    return r
