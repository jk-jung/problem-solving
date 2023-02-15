import numpy as np

def draw_trail(a):
    a = [0] + a
    a = [-x for x in np.cumsum(a)]
    m = min(a)
    a = [x - m for x in a]
    m = max(a)
    r = ['' for _ in range(m + 3)]
    y = -1
    a.append(-100)
    base = a[0] // 3
    for x in a[1:]:
        k = { 0: '_', 1: '-', 2: '‾' }[(a[0] - x) % 3]
        x = base - (a[0] - x) // 3
        for i, _ in enumerate(r):
            if i == x + 2: r[i] += k
            elif y != -1 and y == i: r[i] += c
            else: r[i] += ' '
        y, c = x, k
    while set(r[0]) == {' '}: r = r[1:]
    while set(r[-1]) == {' '}: r = r[:-1]
    return '\n'.join(r)
n