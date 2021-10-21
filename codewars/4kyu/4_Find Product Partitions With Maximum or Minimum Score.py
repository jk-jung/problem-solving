func = ''
r1 = 0
r2 = []


def go(n, s, cnt, p, t):
    global r1, r2, func
    if n == 1:
        if cnt == 1: return
        v = s * cnt
        if (func == 'max' and v > r1) or (func == 'min' and v < r1):
            r1 = v
            r2 = t
        return

    for i in range(p + 1, n + 1):
        if n % i: continue
        go(n, s, cnt, i, t)

        ss = 1
        tt = []
        while n % i == 0:
            cnt += 1
            n //= i
            ss *= i
            tt.append(i)

            go(n, s + ss, cnt, i, tt + t)
        return


def find_spec_prod_part(n, com):
    global func, r1, r2
    r1 = 0
    r2 = []
    func = com
    if func == 'min': r1 = 1 << 50

    go(n, 0, 0, 1, [])

    if len(r2) == 0: return "It is a prime number"
    return [r2, r1]
