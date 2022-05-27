t = {
    '←': (0, -1),
    '↑': (-1, 0),
    '→': (0, 1),
    '↓': (1, 0),
    '↖': (-1, -1),
    '↗': (-1, 1),
    '↘': (1, 1),
    '↙': (1, -1),
}


def count_deaf_rats(v):
    n, m = len(v), len(v[0])
    for i in range(n):
        for j in range(m):
            if v[i][j] == 'P':
                yp, xp = i, j

    def dis(y, x):
        return (yp - y) ** 2 + (xp - x) ** 2

    r = 0
    for i in range(n):
        for j in range(m):
            k = v[i][j]
            if k in t:
                dy, dx = t[k]
                y = i + dy
                x = j + dx
                if dis(i, j) < dis(y, x):
                    r += 1
    return r