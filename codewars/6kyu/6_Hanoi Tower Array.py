import copy

def hanoiArray(n):
    s = [list(range(n, 0, -1)) if i == 0 else [] for i in range(3)]
    r = [copy.deepcopy(s)]

    def dfs(k, x, y):
        if k == 0: return
        z = 3 - x - y
        dfs(k - 1, x, z)

        s[y].append(s[x].pop())
        r.append(copy.deepcopy(s))

        dfs(k - 1, z, y)

    dfs(n, 0, 2)
    return '\n'.join(str(x) for x in r)