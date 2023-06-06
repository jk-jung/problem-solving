def cut(s):
    v = s.split('\n')
    n, m = len(v), len(v[0])
    cnt = s.count('o')
    print(n, m, cnt)

    rec = []
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i * j * cnt == n * m:
                rec.append((i, j))
    rec.sort(key=lambda x: -x[1])
    r = []
    b = [[0 for _ in range(m)] for _ in range(n)]

    def first_empty():
        for i in range(n):
            for j in range(m):
                if b[i][j] == 0:
                    return i, j

    def ok(y, x, box):
        cc = 0
        if box[0] + y > n or box[1] + x > m: return False
        for i in range(box[0]):
            for j in range(box[1]):
                if b[i + y][j + x]: return False
                if v[i + y][j + x] == 'o': cc += 1
        return cc == 1

    def place(y, x, box, val=1):
        if val == 1: r.append((y, x, box))
        else: r.pop()
        for i in range(box[0]):
            for j in range(box[1]):
                b[i + y][j + x] = val

    def f(dep=0):
        if dep == cnt:
            return True
        else:
            y, x = first_empty()
            for box in rec:
                if ok(y, x, box):
                    place(y, x, box, 1)
                    if f(dep + 1): return True
                    place(y, x, box, 0)
        return False
    f()
    rr = []
    for y, x, box in r:
        t = ''
        for i in range(box[0]):
            for j in range(box[1]):
                t += v[i + y][j + x]
            t += '\n'
        rr.append(t.strip())
    return rr
