def pascal(n):
    r = [[1]]
    for i in range(2, n + 1):
        t = [r[-1][x] + r[-1][x + 1] for x in range(len(r[-1]) - 1)]
        r.append([1] + t + [1])
    return r
