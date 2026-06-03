def seven(m):
    a = [m]
    while a[-1] >= 100:
        a.append(a[-1] // 10 - a[-1] % 10 * 2)
    return a[-1], len(a) - 1