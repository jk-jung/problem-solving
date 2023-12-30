def climb(n):
    r = []
    while n:
        r.append(n)
        n //= 2

    return r[::-1]
