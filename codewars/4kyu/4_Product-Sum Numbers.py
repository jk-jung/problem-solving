r = [99999999 for _ in range(30000)]

def go(x, cnt, cur, s):
    k = cur - s + cnt
    if k > 15000: return
    if k > 1: r[k] = min(r[k], cur)

    while x * cur < 30000:
        go(x, cnt + 1, cur * x, s + x)
        x += 1

go(2, 0, 1, 0)

def productsum(n):
    t = set()
    for i in range(2, n+1):t.add(r[i])
    return sum(t)