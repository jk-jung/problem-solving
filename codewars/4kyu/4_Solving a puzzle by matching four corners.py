def find(pp, l1, l2, u2):
    return pp[(l1, l2, u2)]

def puzzle_solver(pieces, width, height):
    p = {x[-1]: x for x in pieces}
    pp = {(x[0][0], x[1][0], x[0][1]): x[-1] for x in pieces}
    r = []
    for i in range(height):
        r.append([])
        for j in range(width):
            t = find(
                pp,
                None if j == 0 else p[r[i][j - 1]][0][1],
                None if j == 0 else p[r[i][j - 1]][1][1],
                None if i == 0 else p[r[i - 1][j]][1][1]
            )
            r[-1].append(t)

    return [tuple(x) for x in r]