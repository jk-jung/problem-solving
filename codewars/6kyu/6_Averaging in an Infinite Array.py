def find_a(a, n):
    if n < 0:
        a = a[::-1]
        n = 3 - n

    b = [
        0,
        a[1] * 3 - a[0] - a[2],
        a[2] * 3 - a[1] - a[3],
        0
    ]
    b[0] = 3 * b[1] - a[1] - b[2]
    b[3] = 3 * b[2] - a[2] - b[1]

    while len(a) <= n:
        a.append(a[-1] * 3 - a[-2] - b[-1])
        b.append(b[-1] * 3 - b[-2] - a[-2])

    return a[n]
