def trailing_zeros(num, base):
    print(num, base)

    r = []
    m = int(base ** .5)

    def cnt(k):
        c2, k2 = 0, k
        while k2 <= num:
            c2 += num // k2
            k2 *= k
        return c2

    for k in range(2, min(m + 1, 10000000)):
        c = 0
        while base % k == 0:
            c += 1
            base //= k
        if c: r.append(cnt(k) // c)

    if base != 1:
        r.append(cnt(base))

    return 0 if len(r) == 0 else min(r)