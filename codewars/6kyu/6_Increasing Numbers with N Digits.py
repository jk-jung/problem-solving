def increasing_numbers(n):
    r = [0 for i in range(10)]
    r[0] = 1
    for _ in range(n):
        t = [0 for i in range(10)]
        for i in range(10):
            for j in range(0, i + 1):
                t[i] += r[j]
        r = t
    return sum(r)
