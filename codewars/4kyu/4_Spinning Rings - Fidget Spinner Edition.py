def gcd(a, b): return a if b == 0 else gcd(b, a % b)

def can(x, y, t):
    return (x - t % x) % x == t % y


def spinning_rings(x, y):
    x, y = x + 1, y + 1
    print(x, y)


    if x % 2 == 0 and y > x // 2:
        return x // 2

    if x <= y:
        t = (x - y % x) % x
        if t % 2 == 0:
            return y + t // 2
        if y % x % 2 == 0:
            return y + x - y % x // 2
        # 2y
    else:
        t = x % y
        print(t)
        r = [
            x - t // 2,
            x - (t + y) // 2,
            x + (x - t) // 2,
            x + (x - t),
            2 * x - (t * 2 + y) // 2,
            ]
        r = sorted([k for k in r if can(x, y, k)])
        return r[0]
    l = x * y // gcd(x, y)
    return None