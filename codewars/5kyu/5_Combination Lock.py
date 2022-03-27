import copy


def combination_lock(t, comb):
    def f(angle):
        v = copy.deepcopy(t)
        while angle:
            nt = []
            if len(v[0]) == 1:
                n = max(len(x) for x in v)
                nt = [[] for _ in range(n)]
                for k in range(n):
                    for i in range(len(v)):
                        for j in range(len(v[i])):
                            if v[i][j] != -1:
                                nt[k].append(v[i][j])
                                v[i][j] = -1
                                break
                        if len(nt[k]) == n: break
                nt = [list(reversed(x)) for x in nt]
            else:
                n = len(v)
                for i in range(n * 2 - 1):
                    nt.append([])
                    y, x = i, 0
                    for j in range(n):
                        if 0 <= y < n and 0 <= x < n:
                            nt[-1].append(v[y][x])
                        y -= 1
                        x += 1
            v = nt
            angle -= 45
        return v
    return [f(x) for x in comb]