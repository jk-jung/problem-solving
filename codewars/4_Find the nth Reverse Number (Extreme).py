def count(m, first=True):
    if not first or m <= 1: return 10 ** ((m + 1) // 2)
    return 9 * 10 ** ((m - 1) // 2)


def go(n, m, first=True):
    if m == 0: return ''
    if m == 1 and n <= 10: return f'{n - 1}'

    tot = count(m, first)
    if n <= tot:
        t = count(m - 2, False)
        for i in range(1 if first else 0, 10):
            if t >= n:
                return f'{i}{go(n, m - 2, False)}{i}'
            n -= t;

    return go(n - tot, m + 1)


def find_reverse_number(n):
    return int(go(n, 1))
