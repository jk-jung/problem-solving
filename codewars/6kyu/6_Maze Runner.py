def maze_runner(m, d):
    n = len(m)
    for i in range(n):
        for j in range(n):
            if m[i][j] == 2:
                y, x = i, j

    for s in d:
        if s == 'N': y -= 1
        if s == 'S': y += 1
        if s == 'E': x += 1
        if s == 'W': x -= 1

        if x < 0 or x == n or y < 0 or y == n or m[y][x] == 1:
            return 'Dead'
        if m[y][x] == 3:
            return 'Finish'

    return 'Lost'
