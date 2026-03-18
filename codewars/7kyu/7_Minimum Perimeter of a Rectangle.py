def minimum_perimeter(a):
    r = 1 << 50
    for i in range(1, a):
        if a % i == 0:
            r = min(r, (i + a // i) * 2)
        if i * i > a:
            break
    return r
