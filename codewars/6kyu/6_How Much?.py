def howmuch(m, n):
    r = []
    for x in range(min(m, n), max(m, n) + 1):
        a, b = x - 2, x - 1
        if a % 7 == 0 and b % 9 == 0:
            r.append([f'M: {x}', f'B: {a // 7}', f'C: {b // 9}'])
    return r
