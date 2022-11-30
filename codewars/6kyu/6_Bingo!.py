def bingo(v, numbers):
    v = v[1:]
    def f(t):
        cnt = 0
        for y, x in t:
            c = v[y][x]
            s = 'BINGO'[x] + str(c)
            if isinstance(c, int):
                cnt += 1
                if s not in numbers:
                    return False
        return cnt >= 4

    for i in range(5):
        if f([(i, j) for j in range(5)]): return True
        if f([(j, i) for j in range(5)]): return True
        if f([(j, j) for j in range(5)]): return True
        if f([(j, 4 - j) for j in range(5)]): return True
    return False
