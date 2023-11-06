def zero_count(n):
    r = 0
    rr = []
    for i in range(n + 1):
        for j in range(i, n + 1 - i):
            k = n - i - j
            if k < j: continue
            s = list(str(i * j * k))
            c = 0
            while s and s[-1] == '0':
                c += 1
                s.pop()
            if c == r:
                rr.append([i, j, k])
            elif c > r:
                r = c
                rr = [[i, j, k]]
    return rr
