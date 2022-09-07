def oddity(n):
    i, r = 1, 0
    while i * i <= n:
        if n % i == 0:
            r += 1
            if n // i != i:
                r += 1
        i += 1
    return 'odd' if r % 2 else 'even'