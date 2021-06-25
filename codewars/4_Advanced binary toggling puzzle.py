from collections import Counter


def get_next_op(puzzle):
    n = len(puzzle)
    m = len(puzzle[0])
    c = Counter()

    for i in range(n):
        for j in range(m):
            if puzzle[i][j] == 0:
                c[i] += 1
                c[j + n] += 1

    if len(c) == 0:
        return None
    return c.most_common(1)[0][0]


def toggle(puzzle, k):
    n = len(puzzle)
    m = len(puzzle[0])

    for i in range(n):
        for j in range(m):
            if i == k or j + n == k:
                puzzle[i][j] ^= 1


def find_solution(puzzle):
    r = []
    while True:
        k = get_next_op(puzzle)
        if k is None:
            break
        toggle(puzzle, k)
        r.append(k)
    return r