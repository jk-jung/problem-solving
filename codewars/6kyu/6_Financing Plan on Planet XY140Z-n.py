def finance(n):
    r = 0
    n += 1
    for i in range(n):
        s = i * 2
        e = n + i - 1
        r += (s + e) * (e - s + 1) // 2
    return r