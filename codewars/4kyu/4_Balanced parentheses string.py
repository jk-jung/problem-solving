d = [[0 for _ in range(201)] for _ in range(201)]


def go(n, m):
    if n == 0 and m == 0:
        d[n][m] = 1
        return 1
    if d[n][m] > 0: return d[n][m]

    if n > 0: d[n][m] += go(n - 1, m + 1)
    if m > 0: d[n][m] += go(n, m - 1)

    return d[n][m]


def build(n, m, k):
    if n == 0 and m == 0: return ''

    if n > 0:
        if d[n - 1][m + 1] >= k:
            return '(' + build(n - 1, m + 1, k)
        else:
            k -= d[n - 1][m + 1]
    if m > 0:
        return ')' + build(n, m - 1, k)

    return ''


def balanced_parens(n, k):
    k += 1
    if k < 1 or k > go(n, 0): return None
    return build(n, 0, k)
