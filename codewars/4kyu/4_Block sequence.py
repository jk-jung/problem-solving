cc = [10 ** i for i in range(1, 10)]


def calc(x):
    r = 0
    for c in cc:
        n = len(str(c)) - 1
        if x < c:
            cnt = x - c // 10 + 1
            a = n * cnt * (cnt + 1) // 2
            r += a
            break
        else:
            cnt = c // 10 * 9
            a = n * cnt * (cnt + 1) // 2
            b = n * cnt * (x - c + 1)
            r += a + b

    return r


def calc2(x):
    r = 0
    for c in cc:
        n = len(str(c)) - 1
        if x < c:
            cnt = x - c // 10 + 1
            r += cnt * n
            break
        else:
            cnt = c // 10 * 9
            r += cnt * n
    return r


def solve(n):
    s, e = 1, 500000000
    while s < e:
        m = (s + e) // 2
        if calc(m) >= n:
            e = m
        else:
            s = m + 1

    t = e
    n -= calc(e - 1)

    s, e = 1, t
    while s < e:
        m = (s + e) // 2
        if calc2(m) >= n:
            e = m
        else:
            s = m + 1

    return int(str(e)[n - calc2(e - 1) - 1])
