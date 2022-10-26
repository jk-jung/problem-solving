def shortest_arrang(n):
    s = {0, 1}
    x = 1
    r = -1
    for i in range(2, n):
        x += i
        if x >= n and (x - n) in s:
            r = i
        s.add(x)

    if r == -1: return [-1]
    v = []
    while n > 0:
        n -= r
        v.append(r)
        r -= 1
    return v
