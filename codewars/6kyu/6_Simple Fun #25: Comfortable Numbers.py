def comfortable_numbers(l, r):
    t = 0
    for a in range(l, r + 1):
        mb = min(r, a + sum(map(int, str(a))))
        for b in range(a + 1, mb + 1):
            if b - sum(map(int, str(b))) <= a: t += 1
    return t
