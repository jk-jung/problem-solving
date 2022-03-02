max_n = 2000000

d = [0 for _ in range(max_n)]
d[1] = 1

def go(x):
    if x < max_n and d[x] != 0:
        return d[x]
    if x % 2 == 0:
        r = go(x // 2) + 1
    else:
        r = go(3 * x + 1) + 1

    if x < max_n:
        d[x] = r
    return r


def max_collatz_length(n):
    if type(n) != int or n <= 0: return []
    r = [0, 0]
    for i in range(1, n + 1): r = max(r, [go(i), -i])

    return [-r[1], r[0]]
